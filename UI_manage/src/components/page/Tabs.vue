<template>
    <div class="">
        <div class="crumbs">
            <el-breadcrumb separator="/">
                <el-breadcrumb-item><i class="el-icon-lx-copy"></i> 设备详情</el-breadcrumb-item>
            </el-breadcrumb>
        </div>
        <div class="device_message">
            <el-tabs v-model="message">

                <el-tab-pane :label="`交换机信息`" name="first">
                    <template v-if="message === 'first'">
                        <el-table :data="switchData" height="550" style="width: 100%">
                            <el-table-column prop="id" label="交换机MAC" ></el-table-column>
                            <el-table-column prop="ip" label="IPv4地址"></el-table-column>
                            <el-table-column prop="time" label="连接时间"></el-table-column>
                            <el-table-column prop="OFver" label="OpenFlow版本" width="150"></el-table-column>
                            <!--el-table-column v-for="(item, index) in switchData" :key="index" :label="item" >
                            <template slot-scope="scope">
                                <span :class="getTextClass(scope.row[index],positionsKey[index].color)">
                                     {{scope.row[index]}}
                                </span>
                            </template>
                            </el-table-column-->
                            
                        </el-table>
                    </template>
                </el-tab-pane>
               
                <el-tab-pane :label="`主机信息`" name="second">
                    <template v-if="message === 'second'">
                    <el-table :data="hostData" height="550" style="width: 100%">
                    <el-table-column prop="h_mac" label="MAC地址" ></el-table-column>
                    <el-table-column prop="h_ip" label="IPv4地址"></el-table-column>
                    <el-table-column prop="h_ipv6" label="IPv6地址"></el-table-column>
                    <el-table-column prop="h_switch" label="交换机ID" ></el-table-column>
                    <el-table-column prop="h_port" label="端口" ></el-table-column>
                    <el-table-column prop="h_time" label="连接时间" ></el-table-column>
                    </el-table>
                    </template>
                </el-tab-pane>

                <el-tab-pane :label="`link信息`" name="third">
                    <template v-if="message === 'third'">
                    <el-table :data="linkData" height="550" style="width: 100%\">
                    <el-table-column prop="l_src_switch" label="源MAC" ></el-table-column>
                    <el-table-column prop="l_src_port" label="源端口"></el-table-column>
                    <el-table-column prop="l_dst_switch" label="目的MAC"></el-table-column>
                    <el-table-column prop="l_dst_port" label="目的端口" ></el-table-column>
                    <el-table-column prop="l_type" label="连接类型" ></el-table-column>
                    <el-table-column prop="l_direction" label="方向" ></el-table-column>
                    <el-table-column prop="l_latency" label="时延" ></el-table-column>
                    </el-table>
                    </template>
                </el-tab-pane>

            </el-tabs>
        </div>
    </div>
</template>

<script>
    export default {
        name: 'tabs',
        data() {
            return {
                message: 'first',
                showHeader: false,
                switchData:[
                    {
                    id:'',
                    ip:'',
                    time:'',
                    OFver:''
                    },
                    {
                    id:'',
                    ip:'',
                    time:'',
                    OFver:''
                    },
                    {
                    id:'',
                    ip:'',
                    time:'',
                    OFver:''
                    },
                    {
                    id:'',
                    ip:'',
                    time:'',
                    OFver:''
                    },
                    {
                    id:'',
                    ip:'',
                    time:'',
                    OFver:''
                    }
                ],

                hostData:[
                    {
                        h_mac:'2e:47:be:41:31:a0',
                        h_ip:'10.0.0.4',
                        h_ipv6:'fe80::2c47:beff:fe41:31a0',
                        h_switch:'00:00:00:00:00:00:00:04',
                        h_port:'3',
                        h_time:'1587137469230',
                    },
                    {
                        h_mac:'8e:21:42:b6:65:89',
                        h_ip:'10.0.0.3',
                        h_ipv6:'fe80::8c21:42ff:feb6:6589',
                        h_switch:'00:00:00:00:00:00:00:03',
                        h_port:'3',
                        h_time:'1587137469266',
                    },
                    {
                        h_mac:'ae:a8:57:ed:95:4b',
                        h_ip:'10.0.0.5',
                        h_ipv6:'fe80::aca8:57ff:feed:954b',
                        h_switch:'00:00:00:00:00:00:00:05',
                        h_port:'2',
                        h_time:'1587137469270',
                    },                
                    {
                        h_mac:'ce:42:ed:ce:c0:27',
                        h_ip:'10.0.0.1',
                        h_ipv6:'fe80::cc42:edff:fece:c027',
                        h_switch:'00:00:00:00:00:00:00:01',
                        h_port:'2',
                        h_time:'1587137468984',
                    },                    

                ],
                linkData:[
                   {
                    l_src_switch:'',
                    l_src_port:'',
                    l_dst_switch:'',
                    l_dst_port:'',
                    l_type:'',
                    l_direction:'',
                    l_latency:''
                   },
                   {
                    l_src_switch:'',
                    l_src_port:'',
                    l_dst_switch:'',
                    l_dst_port:'',
                    l_type:'',
                    l_direction:'',
                    l_latency:''
                   },
                   {
                    l_src_switch:'',
                    l_src_port:'',
                    l_dst_switch:'',
                    l_dst_port:'',
                    l_type:'',
                    l_direction:'',
                    l_latency:''
                   },
                   {
                    l_src_switch:'',
                    l_src_port:'',
                    l_dst_switch:'',
                    l_dst_port:'',
                    l_type:'',
                    l_direction:'',
                    l_latency:''
                   },
                   
                                 
                ],


            };
            },
            mounted(){
                this.getSwitch();
                this.getLink();              
            },
        methods: {
            getSwitch() {
                this.axios.get('http://localhost:8080/wm/core/controller/switches/json')
                .then(switch_res=>{
                        var t = new Date();
                        for(var i=0;switch_res!=null;i++)
                        {
                            this.switchData[i].id=switch_res.data[i]['switchDPID'];                    
                            this.switchData[i].ip=switch_res.data[i]['inetAddress'];
                            t.setTime(switch_res.data[i]['connectedSince']);
                            this.switchData[i].time=t.toString();
                            this.switchData[i].OFver=switch_res.data[i]['openFlowVersion'];
                        }                      
                })
                .catch(function(error){
                    console.log(error);
                 });
            },
            getHost() {
                
            },
            getLink() {
                 this.axios.get('http://localhost:8080/wm/topology/links/json')
                .then(link_res=>{
                     
                    //link_res = link_res.replaceAll("-","");
                    //this.linkData2 = link_res.data; 
                        for(var i=0;link_res!=null;i++)
                        {
                            this.linkData[i].l_src_switch=link_res.data[i]['src-switch'];                    
                            this.linkData[i].l_src_port=link_res.data[i]['src-port'];
                            this.linkData[i].l_dst_switch=link_res.data[i]['dst-switch'];
                            this.linkData[i].l_dst_port=link_res.data[i]['dst-port'];
                            this.linkData[i].l_type=link_res.data[i]['type'];
                            this.linkData[i].l_direction=link_res.data[i]['direction'];
                            this.linkData[i].l_latency=link_res.data[i]['latency'];
                        }    
                                
                })
                .catch(function(error){
                    console.log(error);
                 });
            }
        },
       
        
    }

</script>
<!--script>
export default {
    name: 'switch_message',
    data() {
        return {
            message:'first',
            switchData:[
                {
                    id:'',
                    ip:'',
                    time:'',
                    OFver:''
                },
                {
                    id:'',
                    ip:'',
                    time:'',
                    OFver:''
                },
                {
                    id:'',
                    ip:'',
                    time:'',
                    OFver:''
                },
                {
                    id:'',
                    ip:'',
                    time:'',
                    OFver:''
                },
                {
                    id:'',
                    ip:'',
                    time:'',
                    OFver:''
                }
            ]

        };
    },
   mounted(){
            this.axios.get('http://localhost:8080/wm/core/controller/switches/json',
            {
                params:{
                    ID:1
                }
            } )
            .then(Response => {
                var t = new Date();
                for(var i=0;Response.data!=null;i++)
                {
                        this.switchData[i].id=Response.data[i].switchDPID;                    
                        this.switchData[i].ip=Response.data[i].inetAddress;
                        t.setTime(Response.data[i].connectedSince);
                        this.switchData[i].time=t.toString();
                        this.switchData[i].OFver=Response.data[i].openFlowVersion;
                }
   
            }
            )
            .catch(function(error){
                console.log(error);
            })
            .then(function(){

            });
            
        }
}
</script-->


<!--script>
export default {
    name: 'host_message',
    data() {
        return {
            message:'second',
            hostData:[
                {
                    h_mac:'',
                    h_ip:'',
                    h_ipv6:'',
                    switch:'',
                    port:'',
                    h_time:''
                },
               
            ]

        };
    },
   mounted(){
            this.axios.get('http://localhost:8080/wm/device/',
            {
                params:{
                    ID:2
                }
            } )
            .then(h_res => {
                var t2 = new Date();
                for(var i=0;h_res.data!=null;i++)
                {
                        this.hostData[i].h_mac=h_res.data[i].mac;                    
                        this.hostData[i].h_ip=h_res.data[i].ipv4;
                        this.hostData[i].h_ipv6=h_res.data[i].ipv6;
                        this.hostData[i].switch = h_res.data[i].attachmentPoint.switch;                       
                        this.hostData[i].port = h_res.data[i].attachmentPoint.port;
                        t2.setTime(h_res.data[i].lastSeen);
                        this.hostData[i].h_time=t2.toString();
                        
                }
   
            }
            )
            .catch(function(error){
                console.log(error);
            })
            .then(function(){

            });
            
        }
}
</script-->

<style>
.message-title{
    cursor: pointer;
}
.handle-row{
    margin-top: 30px;
}
</style>

