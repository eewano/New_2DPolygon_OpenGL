#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Define.h"
#include "Utility.h"
#include "Shader.hpp"
#include "Quadrangle.hpp"
#include "Triangle.hpp"

GLFWwindow *window;

int main(int argc, const char *argv[]) {

    //当プロジェクトの作業ディレクトリを表示
    std::cout << "Current directory is " << GetCurrentWorkingDir().c_str() << ".\n";

    //GLFWの初期化(失敗したら終了)
    if (!glfwInit()) {
        return EXIT_FAILURE;
    }

    //GLFWにて要求されるオプションのセット
    //(window生成時に一緒に作成されるコンテキストやスワップチェイン、深度バッファの情報等の指定)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); //Macの際には必要
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    //GLFWの機能を用いて、GLFWwindowオブジェクトを生成
    window = glfwCreateWindow(WINDOW_SIZE.x, WINDOW_SIZE.y, "New_2DPolygon_OpenGL", nullptr, nullptr);

    Vec2i screen;
    //glViewportで必要とされるフレームバッファのサイズを取得
    glfwGetFramebufferSize(window, &screen.x, &screen.y);

    //window生成失敗時のプログラムの終了処理
    if (window == nullptr) {
        std::cout << "Failed to create GLFW window.\n";
        glfwTerminate();
        return EXIT_FAILURE;
    }

    //エラー時に呼ばれるコールバックを設定
    glfwSetErrorCallback(ErrorCallback);

    //windowのコンテキストをカレントにする
    glfwMakeContextCurrent(window);

    //最新の方法でポインターや拡張機能を検索し、glewを有効にする(コアプロファイルで必要)
    glewExperimental = GL_TRUE;

    //GLEWの初期化
    if (glewInit() != GLEW_OK) {
        std::cout << "Failed to initialize GLEW.\n";
        return -1;
    }

    //ビューポートの定義(ウィンドウの左下隅が原点で、そこからx,yの数値分が左下の原点座標となる)
    glViewport(0, 0, screen.x, screen.y);

    //各シェーダー(vert, frag)ファイルの読み込み
    auto shader = std::make_unique<Shader>();
    //ポリゴンのクラスの生成
    auto quadrangle = std::make_unique<Quadrangle>();
    auto triangle = std::make_unique<Triangle>();


    while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0) {
        //キーが押されたりマウスを操作した等、該当する応答機能が何かしら作動したかどうかをチェックする
        glfwPollEvents();

        //glViewportで指定した範囲をこれで指定した色で塗り潰す
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        //指定したバッファを特定の色で消去する
        glClear(GL_COLOR_BUFFER_BIT);

        //設定したシェーダーの使用
        shader->Use();
        quadrangle->Draw(GL_TRIANGLE_FAN);
        triangle->Draw(GL_TRIANGLE_FAN);
        
        //四角形の移動
        quadrangle->Move();
        triangle->Move();

        //スクリーンバッファの交換(ダブルバッファのスワップ)
        glfwSwapBuffers(window);
    }

    quadrangle->DeleteVAO();

    //GLFW使用の際はプログラムの最後にこれを呼び出し、全てのウィンドウの破棄及びリソースの解放を行なう。
    //これを呼び出した後に再度GLFW機能を利用する場合は改めてglfwInitを呼び出す必要がある。
    glfwTerminate();

    return 0;
}
