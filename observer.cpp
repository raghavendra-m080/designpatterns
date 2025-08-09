#include <iostream>
#include <vector>
#include <algorithm>

class ISubscribers
{
public:
    virtual void update() = 0;
    virtual ~ISubscribers() = default;
};

class IPublisher
{
public:
    virtual void addSubs(ISubscribers *) = 0;
    virtual void removSubs(ISubscribers *) = 0;
    virtual void notifySubs() = 0;
    virtual ~IPublisher() = default;
};

class WeatherStation : public IPublisher
{
    std::vector<ISubscribers *> subs;

public:
    void addSubs(ISubscribers *s) override
    {
        subs.push_back(s);
    }
    void removSubs(ISubscribers *s) override
    {
        subs.erase(std::remove(subs.begin(), subs.end(), s), subs.end());
    }
    void notifySubs() override
    {
        for (auto s : subs)
            s->update();
    }
    virtual ~WeatherStation() = default;
};

class IUi
{
public:
    virtual void display() = 0;
};
/* Concrete UI Subscribers*/
class FrontPanelUi : public ISubscribers, public IUi
{
public:
    void update() override
    {
        std::cout << "FrontPanelUi updated" << std::endl;
        display();
    }
    void display() override
    {
        std::cout << "FrontPanelUi display" << std::endl;
    }
};
class SmartPhoneUi : public ISubscribers, public IUi
{
public:
    void update() override
    {
        std::cout << "SmartPhoneUi updated" << std::endl;
        display();
    }
    void display() override
    {
        std::cout << "SmartPhoneUi display" << std::endl;
    }
};

int main()
{
    WeatherStation ws;
    FrontPanelUi fp;
    SmartPhoneUi sp;
    ws.addSubs(&fp);
    ws.addSubs(&sp);
    ws.notifySubs();
}