#include <string>
#include <vector>
#include <iostream>

#include "LDL\LDL.hpp"
#include "LUI\LUI.hpp"

int main()
{
  LDL::Canvas * Screen = new LDL::Canvas(LDL::Rect(0, 0, 800, 600));

  LDL::Event Report = {0};

  bool Running = true;

  while (Running)
  {
    if (Screen->WaitEvent(Report))
    {
      if (Report.Type == LDL::Event::IsQuit)
      {
        Running = false;
        Screen->StopEvent();
      }
      else if (Report.Type == LDL::Event::IsMouseButton)
      {
        if (Report.MouseButton.Button == LDL::Event::ButtonLeft)
        {
          if (Report.MouseButton.State == LDL::Event::ButtonDown)
          {
            uint16_t x = Report.MouseButton.PosX;
            uint16_t y = Report.MouseButton.PosY;
            

              Screen->SetColor(LDL::Color(0, 162, 232, 0));
              Screen->DrawRect(LDL::Rect(x, y, 50, 50));


            std::cout << "Left Down" << std::endl;
          }

          if (Report.MouseButton.State == LDL::Event::ButtonUp)
          {
            std::cout << "Left Up" << std::endl;
          }
        }

        if (Report.MouseButton.Button == LDL::Event::ButtonRight)
        {
          if (Report.MouseButton.State == LDL::Event::ButtonDown)
          {
            std::cout << "Right Down" << std::endl;
          }

          if (Report.MouseButton.State == LDL::Event::ButtonUp)
          {
            std::cout << "Right Up" << std::endl;
          }
        }
      }
        

      Screen->SetColor(LDL::Color(255, 255, 255));

      Screen->Present();
      Screen->DrawText(0, 0, "Text!");
    }
  }

  return 0;
}