<!--template>
    <div>
     <div class="crumbs">
            <el-breadcrumb separator="/">
                <el-breadcrumb-item>
                    <i class="el-icon-pie-chart"></i> 网络拓扑信息
                </el-breadcrumb-item>
            </el-breadcrumb>
        </div>
       <div class="container">
            <div class="plugins-tips">
                vue-schart：vue.js封装sChart.js的图表组件。
                访问地址：
                <a
                    href="https://github.com/lin-xin/vue-schart"
                    target="_blank"
                >vue-schart</a>
            </div>
            <div class="schart-box">
                <div class="content-title">柱状图</div>
                <schart class="schart" canvasId="bar" :options="options1"></schart>
            </div>
            <div class="schart-box">
                <div class="content-title">折线图</div>
                <schart class="schart" canvasId="line" :options="options2"></schart>
            </div>
            <div class="schart-box">
                <div class="content-title">饼状图</div>
                <schart class="schart" canvasId="pie" :options="options3"></schart>
            </div>
            <div class="schart-box">
                <div class="content-title">环形图</div>
                <schart class="schart" canvasId="ring" :options="options4"></schart>
            </div>
        </div>
    </div>
</template>






<script>
import Schart from 'vue-schart';
export default {
    name: 'basecharts',
    components: {
        Schart
    },
    data() {
        return {
            options1: {
                type: 'bar',
                title: {
                    text: '最近一周各品类销售图'
                },
                bgColor: '#fbfbfb',
                labels: ['周一', '周二', '周三', '周四', '周五'],
                datasets: [
                    {
                        label: '家电',
                        fillColor: 'rgba(241, 49, 74, 0.5)',
                        data: [234, 278, 270, 190, 230]
                    },
                    {
                        label: '百货',
                        data: [164, 178, 190, 135, 160]
                    },
                    {
                        label: '食品',
                        data: [144, 198, 150, 235, 120]
                    }
                ]
            },
            options2: {
                type: 'line',
                title: {
                    text: '最近几个月各品类销售趋势图'
                },
                bgColor: '#fbfbfb',
                labels: ['6月', '7月', '8月', '9月', '10月'],
                datasets: [
                    {
                        label: '家电',
                        data: [234, 278, 270, 190, 230]
                    },
                    {
                        label: '百货',
                        data: [164, 178, 150, 135, 160]
                    },
                    {
                        label: '食品',
                        data: [114, 138, 200, 235, 190]
                    }
                ]
            },
            options3: {
                type: 'pie',
                title: {
                    text: '服装品类销售饼状图'
                },
                legend: {
                    position: 'left'
                },
                bgColor: '#fbfbfb',
                labels: ['T恤', '牛仔裤', '连衣裙', '毛衣', '七分裤', '短裙', '羽绒服'],
                datasets: [
                    {
                        data: [334, 278, 190, 235, 260, 200, 141]
                    }
                ]
            },
            options4: {
                type: 'ring',
                title: {
                    text: '环形三等分'
                },
                showValue: false,
                legend: {
                    position: 'bottom',
                    bottom: 40
                },
                bgColor: '#fbfbfb',
                labels: ['vue', 'react', 'angular'],
                datasets: [
                    {
                        data: [500, 500, 500]
                    }
                ]
            }
        };
    }
};
</script>

<style scoped>
.schart-box {
    display: inline-block;
    margin: 20px;
}
.schart {
    width: 600px;
    height: 400px;
}
.content-title {
    clear: both;
    font-weight: 400;
    line-height: 50px;
    margin: 10px 0;
    font-size: 22px;
    color: #1f2f3d;
}
</style-->

<template>
<div>
    <div class="crumbs">
            <el-breadcrumb separator="/">
                <el-breadcrumb-item>
                    <i class="el-icon-pie-chart"></i> 网络拓扑信息
                </el-breadcrumb-item>
            </el-breadcrumb>
    </div>
   <div id="visualization" style="wdith:100%;height:450px"> 

   </div>
</div>
</template>

<script>
//按需引入
import { DataSet, Network } from 'vis/index-network';
//const vis = require("vis-network/dist/vis-network.min.js");
//require("vis-network/dist/vis-network.min.css");
export default {
  name: 'VisNetWork',
  data () {
    return {
      network: null
    }
  },
  mounted(){
    this.create();
  },
  methods: {
    create () {
      // create an array with nodes
      var nodes = new DataSet([
          {id: 1, label: 'h 127.0.0.1',color:'rgb(144,255,144)',size:'10'},
          {id: 2, label: 'h 127.0.0.2',color:'rgb(144,255,144)',size:'10'},
          {id: 3, label: 'h 127.0.0.3',color:'rgb(144,255,144)',size:'10'},
          {id: 4, label: 'h 127.0.0.4',color:'rgb(144,255,144)',size:'10'},
          {id: 5, label: 'h 127.0.0.5',color:'rgb(144,255,144)',size:'10'},
          {id: 6,label: 'S 00:00:00:00:00:00:01',shape:'square',size:'20'},
          {id: 7,label: 'S 00:00:00:00:00:00:02',shape:'square',size:'20'},
          {id: 8,label: 'S 00:00:00:00:00:00:03',shape:'square',size:'20'},
          {id: 9,label: 'S 00:00:00:00:00:00:04',shape:'square',size:'20'},
          {id: 10,label: 'S 00:00:00:00:00:00:05',shape:'square',size:'20'},

      ]);

      // create an array with edges
      var edges = new DataSet([
          {from: 1, to: 6},
          {from: 2, to: 7},
          {from: 3, to: 8},
          {from: 4, to: 9},
          {from: 5, to: 10},
          {from: 6, to: 7},
          {from: 7, to: 8},
          {from: 8, to: 9},
          {from: 9, to: 10}

      ]);

      // create a network
      var container = document.querySelector('#visualization');

      // provide the data in the vis format
      var data = {
          nodes: nodes,
          edges: edges
      };
      var options = {};

      // initialize your network!
      this.network = new Network(container, data, options);
    }
  }
}
</script>


