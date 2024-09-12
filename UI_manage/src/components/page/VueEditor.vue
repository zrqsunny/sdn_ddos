<template>
    <div>
        <div class="crumbs">
            <el-breadcrumb separator="/">
                <el-breadcrumb-item>
                    <i class="el-icon-lx-calendar"></i>流表管理
                </el-breadcrumb-item>
                <el-breadcrumb-item>下发流表</el-breadcrumb-item>
            </el-breadcrumb>
        </div>
        <div class="container">
            <div class="form-box">
                <el-form ref="form" :model="form" label-width="100px" inline="true" >

                    <el-form-item label="交换机 *">
                        <el-select v-model="form.switch" placeholder="请选择">
                            <el-option key="s1" label="00:00:00:00:00:00:00:01" value="00:00:00:00:00:00:00:01"></el-option>
                            <el-option key="s2" label="00:00:00:00:00:00:00:02" value="00:00:00:00:00:00:00:02"></el-option>
                            <el-option key="s3" label="00:00:00:00:00:00:00:03" value="00:00:00:00:00:00:00:03"></el-option>
                            <el-option key="s4" label="00:00:00:00:00:00:00:04" value="00:00:00:00:00:00:00:04"></el-option>
                            <el-option key="s5" label="00:00:00:00:00:00:00:05" value="00:00:00:00:00:00:00:05"></el-option>
                        </el-select>
                       <label class="red"> &emsp; &emsp; &emsp;注：带 * 为必填项</label>
                    </el-form-item>
                    <label class="match">
                    &emsp; &emsp; &emsp;
                    </label> 
                    <el-row> 
                     <el-form-item label="流表名 *">
                        <el-input v-model="form.name" ></el-input>
                    </el-form-item>                                     
                     <el-form-item label="优先级 *">
                        <el-input v-model="form.priority" ></el-input>
                    </el-form-item>
                    <el-form-item label="软超时(s)">
                        <el-input v-model="form.idleTimeOut" style="width:100px"></el-input>
                    </el-form-item>
                    <el-form-item label="硬超时(s)">
                        <el-input v-model="form.hardTimeOut" style="width:100px"></el-input>
                    </el-form-item>
                    </el-row>

                    <el-row>
                    <el-form-item label="cookie">
                        <el-input v-model="form.cookie" style="width:470px"></el-input>
                    </el-form-item>
                                      
                    <el-form-item label="active">
                        <el-switch v-model="form.active" ></el-switch>
                    </el-form-item>
                    </el-row>                   

                <label class="match">
                &emsp; &emsp; &emsp;
                </label>

                <el-row>                                   
                    <el-form-item label="源MAC">
                        <el-input v-model="form.EtherSrc" style="width:190px"></el-input>
                    </el-form-item>
                    <el-form-item label="目的MAC">
                        <el-input v-model="form.EtherDst" style="width:190px"></el-input>
                    </el-form-item>
                    <el-form-item label="以太网类型">
                        <el-input v-model="form.EtherType" style="width:100px"></el-input>
                    </el-form-item>                     
                    <el-form-item label="入端口">
                        <el-input v-model="form.IngressPort" style="width:100px"></el-input>
                    </el-form-item>
                   </el-row>               
  
                    <el-row>
                    <el-form-item label="源IP">
                         <el-input v-model="form.IPsrc" style="width:190px"></el-input>
                    </el-form-item> 
                    <el-form-item label="目的IP">
                        <el-input v-model="form.IPdst" style="width:190px"></el-input>
                    </el-form-item>
                    <el-form-item label="源端口号" >
                        <el-input v-model="form.srcport" style="width:100px"></el-input>
                    </el-form-item>
                    <el-form-item label="目的端口号" >
                        <el-input v-model="form.dstport" style="width:100px"></el-input>
                    </el-form-item> 
                   </el-row>

                    <label class="match">
                    &emsp; &emsp; &emsp;
                    </label>                      
                  <el-row>

                    <el-form-item label="Action">
                        <el-input type="textarea" rows="3" v-model="form.action" style="width:500px" placeholder="例：output=flood（缺省值为drop）"></el-input>
                    </el-form-item>
                    &emsp; &emsp; &emsp;
                    <el-form-item>
                        <p></p>
                        <el-button type="primary" @click="onSubmit">提交</el-button>
                        &emsp;
                        <el-button>取消</el-button>
                    </el-form-item>
                  </el-row>
                  {{this.serial}}
                </el-form>
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
                EtherSrc: '',
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
		if (this.form.EtherSrc != "") {
			this.serial = this.serial+',"eth_src":'+"\"" + this.form.EtherSrc + "\"";
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