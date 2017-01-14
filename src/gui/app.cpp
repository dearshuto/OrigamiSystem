//
//  app.cpp
//  OrigamiSystem
//
//  Created by Shuto on 2016/12/26.
//
//

#include <GLFW/glfw3.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include "origami_system/gui/rendering_window.hpp"
#include "origami_system/gui/app.hpp"

// 1つのウィンドウしか使わない予定なので、グローバル変数にしておく
GLFWwindow* g_window;

int App::DisplayWidth;
int App::DisplayHeight;

bool App::init()
{
    if (glfwInit() == GL_FALSE)
    {
        return false;
    }
    
    //    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);//サイズを固定にする
    g_window = glfwCreateWindow(640, 480, "Origami System", nullptr, nullptr);
    
    if (!g_window)
    {
        return false;
    }
    
    glfwMakeContextCurrent(g_window);
    
    ImGui_ImplGlfw_Init(g_window, true);

    std::unique_ptr<RenderingWindow> renderingWindow(new RenderingWindow("Render Window"));
    renderingWindow->init();
    m_windows.push_back(std::move(renderingWindow));
    
    return true;
}

void App::mainloop()
{
    while (!glfwWindowShouldClose(g_window))
    {
        const ImVec4 clear_color = ImColor(256, 256, 256);

        glfwWaitEvents();
        ImGui_ImplGlfw_NewFrame();
        
        // rendering
        glViewport(0, 0, GetDisplayWidth(), GetDisplayHeight());
        glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);

        for (auto& window : m_windows)
        {
            window->render();
        }
        
        ImGui::Render();
        glfwSwapBuffers(g_window);
    }

}

void App::fetchDisplaySize()const
{
    glfwGetFramebufferSize(GetMainWindow(), &DisplayWidth, &DisplayHeight);
}

void App::terminate()
{
    ImGui_ImplGlfw_Shutdown();
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
