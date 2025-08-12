# designpatterns
## 👀 Observer Pattern

The **Observer Pattern** defines a one-to-many dependency between objects so that when one object (Publisher) changes state, all its dependents (Subscribers) are automatically notified.

### Benefits
- **Loose Coupling**: Publishers and subscribers are independent.  
- **Scalability**: Easily add or remove subscribers at runtime.  
- **Real-time Updates**: All observers stay in sync automatically.

### Example
```cpp
WeatherStation ws;
FrontPanelUi fp;
SmartPhoneUi sp;
ws.addSubs(&fp);
ws.addSubs(&sp);
ws.notifySubs(); // Updates all subscribers

## 🏭 Factory Pattern

The **Factory Pattern** is a creational design pattern that abstracts object creation, allowing clients to request objects without directly instantiating classes using `new`.  

### Benefits
- **Decoupling**: Client code depends only on interfaces, not concrete classes.  
- **Flexibility**: Easily swap implementations at runtime.  
- **Centralized Creation Logic**: Ideal for complex object initialization.

### Example
```cpp
auto animal = AnimalFactory::create("Dog");
animal->speak(); // Output: Woof!
