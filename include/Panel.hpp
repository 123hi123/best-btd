#ifndef PANEL_HPP
#define PANEL_HPP

#include <string>
#include "Util/GameObject.hpp"

class Panel : public Util::GameObject {
public:
    explicit Panel(const std::string& ImagePath);
    
    Panel(const Panel&) = delete;
    Panel(Panel&&) = delete;
    Panel& operator=(const Panel&) = delete;
    Panel& operator=(Panel&&) = delete;
    
    [[nodiscard]] const std::string& GetImagePath() const { return m_ImagePath; }
    [[nodiscard]] const glm::vec2& GetPosition() const { return m_Transform.translation; }
    
    void SetImage(const std::string& ImagePath);
    void SetPosition(const glm::vec2& Position) { m_Transform.translation = Position; }
    
private:
    void ResetPosition() { m_Transform.translation = {0, 0}; }
    
    std::string m_ImagePath;
};

#endif //PANEL_HPP 