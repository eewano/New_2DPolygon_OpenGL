//OpenGL3のシンタックスを使用
#version 330 core

//main.cppで3要素を使用する場合は、GLSLでも3要素を使用しないといけない
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;

//ourColorとしてのアウトプットデータ
out vec3 ourColor;

//transformの情報
uniform mat4 transform;

void main() {
    //position: xyzを表す   1.0f: w(大きさの比率...数値が高い程小さくなる)
    gl_Position = transform * vec4(position, 2.0f);
    //color: RGB これをourColorに代入
    ourColor = color;
}
