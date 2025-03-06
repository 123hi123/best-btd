#include "App.hpp"

#include "Util/Image.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"
#include "Util/Color.hpp"
#include <filesystem>

void App::Start() {
    LOG_TRACE("Start");
    
    try {
        // 检查资源路径
        std::string resourcePath = RESOURCE_DIR"/Image/Character/panel.png";
        LOG_TRACE("Resource path: {}", resourcePath);
        
        // 检查文件是否存在
        if (!std::filesystem::exists(resourcePath)) {
            LOG_ERROR("Resource file does not exist: {}", resourcePath);
        } else {
            LOG_TRACE("Resource file exists: {}", resourcePath);
        }
        
        // 创建面板并设置在左侧
        m_Panel = std::make_shared<Panel>(RESOURCE_DIR"/Image/Character/panel.png");
        LOG_TRACE("Panel created successfully");
        
        // 设置面板位置在左侧
        m_Panel->SetPosition({-400.0f, 0.0f}); // 根据您的屏幕尺寸调整
        m_Panel->SetZIndex(10);
        m_Panel->SetVisible(true);
        
        // 添加到渲染器
        LOG_TRACE("Adding panel to renderer");
        m_Root.AddChild(m_Panel);
        LOG_TRACE("Panel added to renderer");
        
        m_CurrentState = State::UPDATE;
        // 设置纯白背景
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    } catch (const std::exception& e) {
        LOG_ERROR("Exception in App::Start: {}", e.what());
    }
}

void App::Update() {
    try {
        // 更新渲染器
        m_Root.Update();
        
        // 检查退出条件
        if (Util::Input::IsKeyUp(Util::Keycode::ESCAPE) ||
            Util::Input::IfExit()) {
            m_CurrentState = State::END;
        }
    } catch (const std::exception& e) {
        LOG_ERROR("Exception in App::Update: {}", e.what());
    }
}

void App::End() {
    LOG_TRACE("End");
}
