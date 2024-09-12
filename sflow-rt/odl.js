include('extras/json2.js');

var flowkeys = 'ipsource';
var value = 'frames';
var filter = 'outputifindex!=discard&direction=ingress&sourcegroup=external';
var threshold = 1000;
var groups = {'external':['0.0.0.0/0'],'internal':['10.0.0.2/32']};

var metricName = 'ddos';
var controls = {};
var enabled = true;
var blockSeconds = 20;
var ruleid = 0;

var flowprogrammer = 'http://127.0.0.1:8080/controller/nb/v2/flowprogrammer/default/node/OF/';
var user = 'admin';
var password = 'admin';
var bridge = 's1';

function setOpenFlow(bridge,name,spec) {
  http(flowprogrammer+bridge+'/staticFlow/'+name,'put','application/json',
       JSON.stringify(spec),user,password);
}

function deleteOpenFlow(bridge,name) {
  http(flowprogrammer+bridge+'/staticFlow/'+name,'delete','application/json',
       null,user,password);
}

function block(address) {
  if(!controls[address]) {
     var name = 'block' + ruleid++;
     setOpenFlow(bridge,name,{installInHw:true,name:name, 
                 node:{id:bridge, type:'OF'},
                 priority:'11', etherType:'0x0800', 
                 nwSrc: address, actions:['DROP']});
     controls[address] = { name: name, action:'block', 
                           time: (new Date()).getTime() };
  }
}

function allow(address) {
  if(controls[address]) {
     deleteOpenFlow(bridge,controls[address].name);
     delete controls[address];
  }
}

setEventHandler(function(evt) {
  if(!enabled) return;

  var addr = evt.flowKey;
  block(addr);  
},[metricName]);

setIntervalHandler(function() {
  // remove stale controls
  var stale = [];
  var now = (new Date()).getTime();
  var threshMs = 1000 * blockSeconds;
  for(var addr in controls) {
    if((now - controls[addr].time) > threshMs) stale.push(addr);
  }
  for(var i = 0; i < stale.length; i++) allow(stale[i]);
},10);

setHttpHandler(function(request) {
  var result = {};
  try {
    var action = '' + request.query.action;
    switch(action) {
    case 'block':
       var address = request.query.address[0];
       if(address) block(address);
        break;
    case 'allow':
       var address = request.query.address[0];
       if(address) allow(address);
       break;
    case 'enable':
      enabled = true;
      break;
    case 'disable':
      enabled = false;
      break;
    }
  }
  catch(e) { result.error = e.message }
  result.controls = controls;
  result.enabled = enabled;
  return JSON.stringify(result);
});

setGroups(groups);
setFlow(metricName,{keys:flowkeys,value:value,filter:filter});
setThreshold(metricName,{metric:metricName,value:threshold,byFlow:true,timeout:5});
