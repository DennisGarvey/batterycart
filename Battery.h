class Battery
{
  public:
    Battery(int ledStart, int ledEnd, int id);
    int getStart();
    int getEnd();
    void setCurrent(float c);
    void setVoltage(float c);
    float getVoltage();
    float getCurrent(); 
    int getHue();
    void setHue(int h);
    int getID();
  private: 
    float voltage;
    float current;
    int ledStart;
    int ledEnd;
    int hue;
    int id;
    
};
