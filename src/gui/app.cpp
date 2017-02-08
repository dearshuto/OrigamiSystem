//
//  app.cpp
//  OrigamiSystem
//
//  Created by Shuto on 2016/12/26.
//
//

#include <iostream>
#include <Eigen/Core>
#include <GLFW/glfw3.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include "origami_system/algorithm/straight_skelton.hpp"
#include "origami_system/gui/app.hpp"

// 1つのウィンドウしか使わない予定なので、グローバル変数にしておく
GLFWwindow* g_window;
bool g_isActiveWindow;

int App::DisplayWidth;
int App::DisplayHeight;

void window_size_callback(GLFWwindow* window, int width, int height)
{
    
}

bool App::init()
{
    if (glfwInit() == GL_FALSE)
    {
        return false;
    }
    
    //    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);//サイズを固定にする
    g_window = glfwCreateWindow(640, 480, "Origami System", nullptr, nullptr);
    g_isActiveWindow = true;
    
    glfwSetWindowSizeCallback(g_window, window_size_callback);
    
    // タイマーの初期化
    glfwSetTime(0.0);
    
    if (!g_window)
    {
        return false;
    }
    
    glfwMakeContextCurrent(g_window);
    
    ImGui_ImplGlfw_Init(g_window, true);

    m_algorithm.reset(new StraightSkelton);
    
    return true;
}

void App::mainloop()
{
    double last = 0.0;

    while (!glfwWindowShouldClose(g_window))
    {
        const double kCurrent = glfwGetTime();
        const double kDuration = kCurrent - last;
        
        const ImVec4 clear_color = ImColor(256, 256, 256);

        // アクティブだったらイベント処理をしないことでシステムを軽量化する
        if (g_isActiveWindow)
        {
            glfwPollEvents();
        }
        else
        {
            glfwWaitEvents();
        }
        
        // ウィンドウの切替えが起きたらフラグを切り替る
        glfwSetWindowFocusCallback(g_window
                                   , [](GLFWwindow* window, int focused){
                                       if (focused)
                                       {
                                           g_isActiveWindow = true;
                                       }
                                       else
                                       {
                                           g_isActiveWindow = false;
                                       }
                                   });
        
        ImGui_ImplGlfw_NewFrame();
        
        // rendering
        glViewport(0, 0, GetDisplayWidth(), GetDisplayHeight());
        glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);

        renderRenderingWindow();
        
        // 毎秒呼び出す.
        if (kDuration > 1.0)
        {
            if (m_algorithm)m_algorithm->update();
            last = glfwGetTime();
        }

        ImGui::Render();
        glfwSwapBuffers(g_window);
    }

}

void App::renderRenderingWindow()const
{
    bool canOpen = false;
    ImGui::SetNextWindowPos({0, 0});
    ImGui::SetNextWindowSize(ImVec2{300, 300});
    ImGui::Begin("Rendering Window"
                 , &canOpen
                 , ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar);
    ImDrawList*const drawList = ImGui::GetWindowDrawList();
    const ImVec2& kMousePosition = ImGui::GetIO().MousePos;
    
    for (const auto& shape : m_algorithm->getRenderShapes())
    {
        shape->stackDrawData(drawList, Matrix2::Identity());
        shape->detectMouseEvent(Eigen::Vector2f{kMousePosition.x, kMousePosition.y});
    }
    
    ImGui::End();
}

void App::fetchDisplaySize()const
{
    glfwGetFramebufferSize(GetMainWindow(), &DisplayWidth, &DisplayHeight);
}

void App::terminate()
{
    ImGui_ImplGlfw_Shutdown();
    glfwDestroyWindow(g_window);
    glfwTerminate();
}

GLFWwindow* App::GetMainWindow()
{
    return g_window;
}

unsigned int App::GetDisplayWidth()
{
    return DisplayWidth;
}

unsigned int App::GetDisplayHeight()
{
    return DisplayHeight;
}
