#include <utility>

#include <utility>

#include <utility>

#pragma once

namespace gui
{
  class GuiElement;

  class Gui : public sf::Drawable, public sf::Transformable
  {
   protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

   public:
    bool handleEvent(sf::Event& event);
    template <typename tElement, typename... tArgs> tElement* createElement(tArgs... args)
    {
      return static_cast<tElement*>(m_elements.emplace_back(std::make_unique<tElement>(args...)).get());
    }

   private:
    std::vector<std::unique_ptr<GuiElement>> m_elements;
  };

  class GuiElement : public sf::Drawable, public sf::Transformable
  {
   public:
    virtual bool handleEvent(const sf::Event& event) = 0;
  };

  void Gui::draw(sf::RenderTarget& target, sf::RenderStates states) const
  {
    for(auto& e : m_elements)
      target.draw(*e, states);
  }

  bool Gui::handleEvent(sf::Event& event)
  {
    for(auto& e : m_elements)
    {
      if(e->handleEvent(event))
        return true;
    }
    return false;
  }

  class Label : public GuiElement
  {
   public:
    Label(sf::Font* font, std::string text);

    bool handleEvent(const sf::Event& event) override
    {
      return false;
    }

    void setText(std::string text)
    {
      m_displayString = std::move(text);
    }

   protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
      m_text.setString(m_displayString);
      m_text.setPosition(getPosition());
      target.draw(m_text);
    }

    sf::Font* m_font;
    std::string m_displayString;
    mutable sf::Text m_text;
  };

  Label::Label(sf::Font* font, std::string text)
      : m_font { font }
      , m_displayString { std::move(text) }
  {
    m_text.setFont(*m_font);
  }

  class Button : public Label
  {
   public:
    Button(sf::Font* font, std::string text, std::function<bool(Button*)> onClick)
        : Label(font, std::move(text))
        , m_onClick { std::move(onClick) }
    {
    }

    bool handleEvent(const sf::Event& event) override
    {
      if(event.type == sf::Event::MouseButtonReleased)
        if(m_text.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
          return m_onClick(this);

      return Label::handleEvent(event);
    }

   private:
    std::function<bool(Button*)> m_onClick;
  };

  class RotarySelector : public GuiElement
  {
   public:
    typedef std::pair<std::string, std::string> tEntry;

    RotarySelector(sf::Font* font, std::vector<tEntry> entrys)
        : m_entrys { std::move(entrys) }
        , m_next { font, ">",
                   [&](auto) {
                     incDec(1);
                     return true;
                   } }
        , m_previous { font, "<",
                       [&](auto) {
                         incDec(-1);
                         return true;
                       } }
        , m_currentValue { font, "" }
    {
      m_index = 0;
    }

    tEntry getSelected() const
    {
      return m_entrys[m_index];
    }

    bool handleEvent(const sf::Event& event) override
    {
      return m_next.handleEvent(event) || m_previous.handleEvent(event) || m_currentValue.handleEvent(event);
    }

   protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
      target.draw(m_previous);
      target.draw(m_currentValue);
      target.draw(m_next);
    }

   private:
    void incDec(int i)
    {
      m_index = std::max<size_t>(std::min<size_t>(m_entrys.size() - 1, m_index + i), 0);
      m_currentValue.setText(m_entrys[m_index].second);
    }

    size_t m_index;
    std::vector<tEntry> m_entrys;

    Button m_next;
    Button m_previous;
    Label m_currentValue;
  };
}