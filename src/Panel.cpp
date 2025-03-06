#include "Panel.hpp"
#include "Util/Image.hpp"
#include "Util/Logger.hpp"

Panel::Panel(const std::string& ImagePath) {
    LOG_TRACE("Creating Panel with image: {}", ImagePath);
    SetImage(ImagePath);
    ResetPosition();
}

void Panel::SetImage(const std::string& ImagePath) {
    m_ImagePath = ImagePath;
    try {
        m_Drawable = std::make_shared<Util::Image>(m_ImagePath);
        LOG_TRACE("Image loaded successfully: {}", m_ImagePath);
    } catch (const std::exception& e) {
        LOG_ERROR("Failed to load image: {} - Error: {}", m_ImagePath, e.what());
        // 设置一个默认图像或者处理错误
    }
} 