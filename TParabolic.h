#pragma once
#include <iostream>
#include <math.h>
#include <vector>

struct TPPoint
{
    float x;
    float y;

    sf::Vector2f toV2f_x()
    {
    return sf::Vector2f(x,y);
    }

       sf::Vector2f toV2f_xrev()
    {
    return sf::Vector2f(-x,y);
    }

    operator sf::Vector2f()
    {
    return sf::Vector2f(x,y);
    }


};

class TParabolic
{
private:
    int m_MAX_POINTS = 10;
    float m_ParameterA = -1;
    float m_XMultiplicator = 2;
    std::vector<TPPoint> PPoint;
    std::vector<TPPoint>::iterator it;

public:
    bool isPointToGo = false;

public:
    void Recalculate(const int &setMP = 10, const float &setAParameter = -1, const float &setXMultiplicator = 2)
    {

        m_MAX_POINTS = setMP;
        m_XMultiplicator = setXMultiplicator;
        m_ParameterA = setAParameter;

        PPoint.clear();
        PPoint.resize(m_MAX_POINTS);
        ResetIterator();

        float YShift = m_ParameterA * pow((0 * m_XMultiplicator) - m_MAX_POINTS, 2); // q - coordinate to Y to shift all points

        std::cout << "---------------" << std::endl;
        std::cout << "Y Shift: " << YShift << std::endl;

        for (int i = 0; i < PPoint.size(); i++) // assign x, y coordinates
        {

            PPoint[i].x = ((i + 1) * m_XMultiplicator);                               // Multiply counter (i) and use as X value. (i+1) because i dont need start position as first point.
            PPoint[i].y = m_ParameterA * pow(PPoint[i].x - m_MAX_POINTS, 2) - YShift; // Count Y with shift in X and Y axis ( y=a(x-p)+q )
            if (i == PPoint.size() - 1)
                PPoint[i].y = 0; // Set last Y to 0;

            std::cout << "Punkt" << i;
            if (PPoint[i].y == abs(YShift))
                std::cout << " CENTER ------> ";
            std::cout << "- X: " << PPoint[i].x;
            std::cout << " Y: " << PPoint[i].y;

            std::cout << std::endl;
        };
        std::cout << "---------------" << std::endl;
    };

    void ResetIterator()
    {
        it = PPoint.begin();
        isPointToGo = true;
    }

    const int PointCount()
    {
    return PPoint.size();
    }

     TPPoint *firstPoint()
    {
        return &(*PPoint.begin());
    }

    TPPoint *lastPoint()
    {
        return &(*PPoint.end());
    }

        void Inc()
    {
       it = std::next(it);
         if (it == PPoint.end()-1)
            isPointToGo = false;
    }

          void Dec()
    {
        it = std::prev(it);
    }

    TPPoint *prevPoint()
    {
        return &(*it);
    }

    TPPoint *nextPoint()
    { 
      
        return &(*it);
    }

    TPPoint *getPoint(const int &idx)
    {
        std::advance(it, idx);
        return &(*it);
    };


   const TPPoint TakeCopy(TPPoint* P)
    {
       return *P;
    };


};