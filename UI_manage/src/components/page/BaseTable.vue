<template>
<div>
    <div class="check">
            <el-breadcrumb separator="/">
                <el-breadcrumb-item>
                    <i class="el-icon-lx-cascades"></i> DDoS攻击检测
                </el-breadcrumb-item>
                <el-breadcrumb-item>检测分析</el-breadcrumb-item>
            </el-breadcrumb>
    </div>

        <!--div class="card-header" id="accu">
          <i class="#" id="accuracy"></i> <b>分类准确率</b></div-->
    <div class="card-body" style="text-align: center;">

        <div class="accuracy_table">
            <el-table :data="accuracy" style="width: 100%">
            <el-table-column prop="x" label="RFE选x个特征" ></el-table-column>
            <el-table-column prop="NB" label="朴素贝叶斯(%)"></el-table-column>
            <el-table-column prop="SVM" label="支持向量机(%)"></el-table-column>
            <el-table-column prop="DT" label="决策树(%)" ></el-table-column>
            <el-table-column prop="RF" label="随机森林(%)" ></el-table-column>
            </el-table>


        </div>
    </div>

</div>

</template>
 


<!--script>
import { fetchData } from '../../api/index';
export default {
    name: 'basetable',
    data() {
        return {      
            query: {
                address: '',
                name: '',
                pageIndex: 1,
                pageSize: 10
            },
            tableData: [],
            multipleSelection: [],
            delList: [],
            editVisible: false,
            pageTotal: 0,
            form: {},
            idx: -1,
            id: -1
        };
    },
    created() {
        this.getData();
    },
    methods: {
        // 获取 easy-mock 的模拟数据
        getData() {
            fetchData(this.query).then(res => {
                console.log(res);
                this.tableData = res.list;
                this.pageTotal = res.pageTotal || 50;
            });
        }
        
    }
};
</script-->



<script>
export default {
    data(){
        return{
            accuracy:[
                {
                     x:'1',
                     NB:'80.32525768',
                     SVM:'77.86001',
                     DT:'80.53962227',
                     RF:'80.54124163'
                },
                {
                     x:'2',
                     NB:'80.91632672',
                     SVM:'77.86001',
                     DT:'80.67908934',
                     RF:'80.68374503'
                },
                                {
                     x:'3',
                     NB:'41.27265198',
                     SVM:'77.86001',
                     DT:'81.73835546',
                     RF:'81.74260631'
                },
                {
                     x:'4',
                     NB:'41.21718919',
                     SVM:'77.86001',
                     DT:'81.92255727',
                     RF:'81.92660569'
                },
                 {
                     x:'5',
                     NB:'41.21496263',
                     SVM:'77.86001',
                     DT:'82.84073859',
                     RF:'82.83810711'
                },
                {
                     x:'6',
                     NB:'41.21496263',
                     SVM:' 77.86001',
                     DT:'82.86280247',
                     RF:'82.86179037'
                },
                                {
                     x:'7',
                     NB:'98.16950959',
                     SVM:'99.68007996',
                     DT:'98.75673245',
                     RF:'98.75288645'
                },
                                {
                     x:'8',
                     NB:'98.16950959',
                     SVM:'99.68001',
                     DT:'98.74438488',
                     RF:'98.22072045'
                },
                  {
                     x:'9',
                     NB:'41.53883513',
                     SVM:'99.67007996',
                     DT:'98.92555082',
                     RF:'99.40650321'
                },
                 {
                     x:'10',
                     NB:'41.53397702',
                     SVM:'99.67007996',
                     DT:'98.85612337',
                     RF:'99.82227492'
                }
            ]
        //     NB:[80.32525768,80.91632672,41.27265198,41.21718919,41.21496263
        //     ,41.21273605,98.16950959,42.26572981,41.53883513,41.53397702,41.53438186,
        // 41.49652914,41.48883715,41.50341156,41.71838224,41.7266815,41.7238476,41.69409171,41.67810048,98.38872976,98.37010703,98.38447917,
        // 76.3037953,76.30318804,76.30318804,76.39771863,76.39771863,76.60600997],
        //     SVM:[77.86001,77.86001,77.86001,77.86001,77.86001,77.86001,99.68007996,99.68007996,99.68007996,99.68007996,99.68007996,99.67007996,99.67007996,
        // 99.67007996,99.67007996,99.67007996,99.67007996,99.65009495,99.69001,99.28001,99.28001,99.28001,99.28001,99.28001,99.28001,99.28001,
        // 99.28001,99.28001],
        //     DT:[80.53962227,80.67908934,81.73835546,81.92255727,82.84073859,82.86280247,98.75673245,98.74438488,98.92555082,98.85612337,99.15226234,
        // 99.16663489,99.38889269,99.39557257,99.40427662,99.39172656,99.57856078,99.7307809,99.76276277,99.71236036,99.71397949,99.76863374,
        // 99.78118382,99.77956447,99.7809814,99.78624359,99.78280241,99.78280241],
        //     RF:[80.54124163,80.68374503,81.74260631,81.92660569,82.83810711,82.86179037,98.75288645,98.74519455,98.93283792,98.86644684,99.1609666,
        // 99.17837527,99.41500492,99.40650321,99.43909302,99.43281797,99.62795136,99.7751107,99.77207439,99.76600165,99.76660904,99.78705363,
        // 99.80425936,99.80000859,99.82227492,99.82106031,99.80021098,99.82207204]
         }
    },
    mounted(){
        var url='http://localhost:8080'
        this.axios.get('./public/table.json').then((Response)=>{
            
                this.NB = Response.RFE_NB
                // this.NB = Response.RFE_NB;
                this.SVM = Response.RFE_SVM;
                // this.DT = Response.RFE_DT;
                // this.RF = Response.RFe_RF;
            
        })
    }
}
</script>








 
    <style type="text/css">
#mynetwork {
    width: 600px;
    height: 400px;
    border: 1px solid lightgray;
}
</style>

