//
//  main.cpp
//  read_draw_obj
//
//  Created by depeng LIU on 2017/1/23.
//  Copyright © 2017年 depeng LIU. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

struct vertex_pos
{
    vector<double> vec_pos_x;
    vector<double> vec_pos_y;
    vector<double> vec_pos_z;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "procession begin>>>\n";
    ifstream in;
    in.open("/Users/dp/Documents/all_codes_dp/read_draw_obj/read_draw_obj/cube.obj");
    vertex_pos obj_vertex_pos;
    string this_line;
    double temp_val_x,temp_val_y,temp_val_z;
    
    while(getline(in, this_line)){//while
        //cout<<this_line<<endl;//show this line for check
        if (this_line.substr(0, 2) == "vt") // 顶点纹理坐标数据
        {
            // 解析顶点纹理数据
            cout<<"this is a 'vt' line"<<endl;
            cout<<this_line<<endl;//show this line for check
        }
        else if (this_line.substr(0, 2) == "vn") // 顶点法向量数据
        {
            // 解析法向量数据
            cout<<"this is a 'vn' line"<<endl;
            cout<<this_line<<endl;//show this line for check
        }
        else if (this_line.substr(0, 1) == "v") // 顶点位置数据
        {
            // 解析顶点位置数据
            cout<<"this is a 'v' line"<<endl;
            cout<<this_line<<endl;//show this line for check
            istringstream this_line_stream(this_line.substr(2));
            this_line_stream>>temp_val_x;
            obj_vertex_pos.vec_pos_x.push_back(temp_val_x);
            this_line_stream>>temp_val_y;
            obj_vertex_pos.vec_pos_y.push_back(temp_val_y);
            this_line_stream>>temp_val_z;
            obj_vertex_pos.vec_pos_z.push_back(temp_val_z);
        }
        else if (this_line.substr(0, 1) == "f") // 面数据
        {
            // 解析面数据
            cout<<"this is a 'f' line"<<endl;
            cout<<this_line<<endl;//show this line for check
        }
        else if (this_line[0] == '#') // 注释忽略
        {
            
            cout<<"this is a # line"<<endl;
            cout<<this_line<<endl;//show this line for check
        }
        else  
        {
            // 其余内容 暂时不处理
            cout<<"this is a 'weird' line"<<endl;
            cout<<this_line<<endl;//show this line for check
        }
        
        
    }//while
    
    
    
    
    
    return 0;
}
