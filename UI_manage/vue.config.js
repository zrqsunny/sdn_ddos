module.exports = {
    baseUrl: './',
    assetsDir: 'static',
    productionSourceMap: false,
    // devServer: {
    //     proxy: {
    //         '/api':{
    //             target:'http://jsonplaceholder.typicode.com',
    //             changeOrigin:true,
    //             pathRewrite:{
    //                 '/api':''
    //             }
    //         }
    //     }
    // }
    
    //axios域代理，解决axios跨域问题
    // baseUrl: '/',
    // devServer: {
    //     proxy: {
    //         '':{
    //             target:'http://192.168.0.108:8090',
    //             changeOrigin:true,
    //             ws:true,
    //             pathRewrite:{
                   
    //             }
    //         }
    //     }
    // }
}