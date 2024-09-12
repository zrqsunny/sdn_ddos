import request from '../utils/request';

export const fetchData = query => {
    return request({
       // url: './table.json',
       url:'http://192.168.56.1:8080/wm/core/switch/all/flow/json',
        method: 'get',
        params: query
    });
};
