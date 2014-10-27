//
//  TinySP.cpp
//  5
//
//  Created by LTT on 10/21/14.
//  Copyright (c) 2014 PDL. All rights reserved.
//

#include "TinySP.hpp"

float perimeter(const std::vector<cv::Point2f> &a)
{
    float sum=0, dx, dy;
    
    for (size_t i=0;i<a.size();i++)
    {
        size_t i2=(i+1) % a.size();
        
        dx = a[i].x - a[i2].x;
        dy = a[i].y - a[i2].y;
        
        sum += sqrt(dx*dx + dy*dy);
    }
    
    return sum;
}


bool isInto(cv::Mat &contour, std::vector<cv::Point2f> &b)
{
    for (size_t i=0;i<b.size();i++)
    {
        if (cv::pointPolygonTest( contour,b[i],false)>0) return true;
    }
    return false;
}
