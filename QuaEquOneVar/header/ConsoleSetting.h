// ConsoleSetting.cpp

#pragma once

#include <string>

/**
 * @brief Change foregound and background color in cmd window for output.
 * @param foregroundColor <7> white(DEFAULT), <0> black, <1> blue,
                          <2> green, <3> red, <4> cyan, <5> pink, <6> yellow.
 * @param backgroundColor <0> black(DEFAULT), <1> blue, <2> green, <3> red,
                          <4> cyan, <5> pink, <6> yellow, <7> white.
 * @param foregroundIntensity <true>(DEFAULT), <false>.
 * @param backgroundIntensity <false>(DEFAULT), <true>.
*/
void setOutputColor(int foregroundColor = 7, int backgroundColor = 0,
                    bool foregroundIntensity = true, bool backgroundIntensity = false);

/**
 * @brief Output text in different colors, and re-set the color to default after ouputing.
 * @param str The output string.
 * @param foregroundColor <7> white(DEFAULT), <0> black, <1> blue,
                          <2> green, <3> red, <4> cyan, <5> pink, <6> yellow.
 * @param backgroundColor <0> black(DEFAULT), <1> blue, <2> green, <3> red,
                          <4> cyan, <5> pink, <6> yellow, <7> white.
 * @param foregroundIntensity <true>(DEFAULT), <false>.
 * @param backgroundIntensity <false>(DEFAULT), <true>.
*/
template<class T>
inline void colorfulOutput(const T& str,
                           int foregroundColor = 7, int backgroundColor = 0,
                           bool foregroundIntensity = true, bool backgroundIntensity = false)
{
    setOutputColor(foregroundColor, backgroundColor, foregroundIntensity, backgroundIntensity);
    std::cout << str;
    setOutputColor();
}

/**
 * @brief Set the size of console window.
 * @param line Number of lines of the window.   e.g. <"20">
 * @param colu Number of columns of the window. e.g. <"15">
 * @param fix  <false>(DEFAULT) Whether to fix the size of the window.
*/
void windowSize(const std::string& line, const std::string& colu, bool fix = false);