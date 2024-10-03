class CustomLayout
{
private:
    CustomLayout();
    ~CustomLayout() = default;
    
public:
    static CustomLayout getInstance();
    static void initialize();
    static void destroy();

    void drawLayout() const;
    void exitLayout();

    void setCursorPosition(int posX, int posY) const;
};

CustomLayout::CustomLayout() {}

