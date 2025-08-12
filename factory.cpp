#include <iostream>

class IButton
{
public:
    virtual void render() = 0;
    virtual ~IButton() = default;
};

class WindowButton : public IButton
{
public:
    void render() override
    {
        std::cout << "WindowButton render" << std::endl;
    }
};

class MacButton : public IButton
{
public:
    void render() override
    {
        std::cout << "MacButton render" << std::endl;
    }
};

class Dialog
{
public:
    virtual std::unique_ptr<IButton> createButton() = 0;
    void renderWindow()
    {
        auto btn = createButton();
        btn->render();
    }
    virtual ~Dialog() = default;
};

class WindowDialog : public Dialog
{
public:
    std::unique_ptr<IButton> createButton() override
    {
        return std::make_unique<WindowButton>();
    }
    ~WindowDialog() = default;
};
class MacDialog : public Dialog
{
public:
    std::unique_ptr<IButton> createButton() override
    {
        return std::make_unique<MacButton>();
    }
    ~MacDialog() = default;
};
int main()
{
    std::unique_ptr<Dialog> wd = std::make_unique<WindowDialog>();
    std::unique_ptr<Dialog> md = std::make_unique<MacDialog>();
    wd->renderWindow();
    md->renderWindow();
    return 0;
}