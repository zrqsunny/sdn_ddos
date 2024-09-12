<template>
        <!--iframe src="http://localhost:8080/ui/pages/firewall.html" width="1200" height="500" frameborder="0" scrolling="auto" style="position:absolute;top: 30px;left: 30px;"></iframe-->
<div align="center" style="margin:0 auto;">

    <div style="width:1200px;height:800px;overflow:hidden;border:0px"> 
         <div style="width:1500px;height:500px;margin:-90px 0px 0px -270px;">
              <iFrame src="http://localhost:8080/ui/pages/firewall.html" width="1500" height="600" scrolling="no">
             </iFrame>
         </div> 
     </div> 
</div> 
</template>


<script>
export default {
    name: 'baseform',
    data() {
        return {
           
            form: {
                switch:'',
                name: '',
                priority: '',
                idleTimeOut: '',
                hardTimeOut: '',
                cookie:'',
                active: true,
                EtherSource: '',
                EtherDst: '',
                EtherType: '',
                IngressPort:'',
                IPsrc:'',
                IPdst:'',
                srcport:'',
                dstport:'',
                action:'',
            },
            serial:'',
        };
    },
     created() {
        //this.flow();
    },
    methods: {
        // onSubmit(){
        //     this.$message.success('提交成功！');
        // },
        flow() { 
        this.serial = '{"switch":' + "\"" + this.form.switch + "\"";
		if (this.form.name!="") {
			this.serial = this.serial+',"name":'+"\"" + this.form.name + "\"";		
        }
		if (this.form.priority != "") {
			this.serial = this.serial+',"priority":'+"\"" + this.form.priority + "\"";
		}
		if (this.form.idleTimeOut != "") {
			this.serial = this.serial+',"idle_timeout":'+"\"" + this.form.idleTimeOut + "\"";
		}
		if (this.form.hardTimeOut != "") {
			this.serial = this.serial+',"hard_timeout":'+"\"" + this.form.hardTimeOut + "\"";
        }
       if (this.form.cookie != "") {
			this.serial = this.serial+',"cookie":'+"\"" + this.form.cookie + "\"";
        }
		if (this.form.active != "" ) {
            this.serial = this.serial+',"active":'+"\"" + this.form.active + "\"";
        }
		if (this.form.EtherSource != "") {
			this.serial = this.serial+',"eth_src":'+"\"" + this.form.EtherSource + "\"";
		}
		if (this.form.EtherDst != "" ) {
			this.serial = this.serial+',"eth_dst":'+"\"" + this.form.EtherDst + "\"";
		}
		if (this.form.EtherType != "" ) {
			this.serial = this.serial+',"eth_type":'+"\"" + this.form.EtherType + "\"";
		}
		if (this.form.IngressPort != "" ) {
			this.serial = this.serial+',"in_port":'+"\"" + this.form.IngressPort + "\"";
        }
		if (this.form.IPsrc != "" ) {
			this.serial = this.serial+',"ipv4_src":'+"\"" + this.form.IPsrc + "\"";
		}
		if (this.form.IPdst != "" ) {
			this.serial = this.serial+',"ipv4_dst":'+"\"" + this.form.IPdst + "\"";
        }
 		if (this.form.srcport != "") {
			this.serial = this.serial+',"tp_src":'+"\"" + this.form.srcport + "\"";
		}       
		if (this.form.dstport != "" ) {
			this.serial = this.serial+',"tp_dst":'+"\"" + this.form.dstport + "\"";
		}
		if (this.form.action != "" ) {
			this.serial = this.serial+',"actions":'+"\"" + this.form.action + "\"";
		}
		if(this.form.action =="") {
			this.serial = this.serial+',"actions":'+"\"" + "drop" + "\"";
		}
        
        this.serial += '}';
        },
        // this.$ajax({
        //         type:"POST",
        //         dataType: 'json',               
        //         url: url= 'http://localhost:8080/wm/staticflowpusher/json',
        //         data: this.serial,
                
        //         success: function(data) {
        //             if(data["status"]=="Entry pushed"){
        //                 this.$message.success('提交成功！')
        //                 new PNotify({
        //                     title:'Flow entry added!',
        //                     text:'Flow entry successfully added.',
        //                     type:'success',
        //                     hide:true
        //                 });
        //             }
        //             else{
        //                 this.$message.success('提交失败！');
        //                 new PNotify({
        //                     title:'Error Occured.',
        //                     text:data["status"],
        //                     type:'error',
        //                     hide:true
        //                 })
        //             }
        //         },
        //         error: function (jqXHR, textStatus, errorThrown) {
        //             alert('Error: ' + " " + jqXHR.responseText + " \n Status: " + textStatus + " \n Error Thrown: " + errorThrown);
        //         }

            // });
 pushflow:function(){
        //     this.$message.success('提交成功！');

             var url = 'http://localhost:8080/wm/staticflowpusher/json';
               this.axios.post(url,this.serial).then(function(res) {
                   var resData = res.data;               
                    if(resData.status == "Entry pushed") { //0表示成功，1表示失败    
                        //alert(resData.message);
                       
                    }
                    else{
                         alert(resData.message);
                    } 
                });
        
         }, 
        onSubmit(){
            this.flow();
            this.pushflow();
            this.$message.success('提交成功！');
     
        },    

        
       
       
	

		
	}


};
</script>

<style>
.container{
    display: block;
    margin: auto;
    width: auto;
}

.form-box{
    display: block;
    margin: auto;
    width: auto;

}
.red{
 color: #ff0000;
}
.match{
    position: relative;
    display :block;
    background-color: #edf0f8;
    color: rgb(0, 0, 0);
}
</style>