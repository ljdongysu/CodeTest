#include <iostream>
#include <fstream>
#include <math.h>
#include "cv.h"
#include "opencv2/opencv.hpp"

#define CENTER_POINT(LINE) {(LINE.B.x - LINE.A.x)/2, (LINE.B.y - LINE.A.y)/2, (LINE.B.z - LINE.A.z)/2}
#define LESS_THAN(a, b) if(a < b) return 0

using LOCATION_TYPE = double;
const LOCATION_TYPE DEFAULT_LOCATION = -1;

struct Location
{
    LOCATION_TYPE x;
    LOCATION_TYPE y;
    LOCATION_TYPE z;

    Location()
    {
        this->x = DEFAULT_LOCATION;
        this->y = DEFAULT_LOCATION;
        this->z = DEFAULT_LOCATION;
    }

    Location(const LOCATION_TYPE x, const LOCATION_TYPE y, const LOCATION_TYPE z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    Location &operator=(const Location &l)
    {
        this->x = l.x;
        this->y = l.y;
        this->z = l.z;

        return *this;
    }

    Location operator-(const Location &l) const
    {
        Location ret;
        ret.x = this->x - l.x;
        ret.y = this->y - l.y;
        ret.z = this->z - l.z;

        return ret;
    }

    Location operator+(const Location &l) const
    {
        Location ret;
        ret.x = this->x + l.x;
        ret.y = this->y + l.y;
        ret.z = this->z + l.z;

        return ret;
    }

    Location operator/(const Location &l) const
    {
        Location ret;
        ret.x = this->x / l.x;
        ret.y = this->y / l.y;
        ret.z = this->z / l.z;

        return ret;
    }

    float Distance(const Location &l) const
    {
        Location diff = *this - l;
        return sqrt(diff.x * diff.x + diff.y * diff.y + diff.z * diff.z);
    }

    bool Write(std::ofstream &stream) const
    {
        if (!stream.is_open())
        {
            return false;
        }

        stream << this->x << ",";
        stream << this->y << ",";
        stream << this->z;

        return true;
    }

    bool Read(std::ifstream &stream)
    {
        if (!stream.is_open())
        {
            return false;
        }

        char flag;
        stream >> this->x >> flag;
        stream >> this->y >> flag;
        stream >> this->z;

        return true;
    }

    std::string Print() const
    {
        char message[100];
        sprintf(message, "x,y,z : %.2f, %.2f, %.2f", x, y, z);
        return message;
    }
};

enum Axis
{
    X = 0, Y, UNKNOWN
};

struct Line
{
    Line() : A({0, 0, 0}), B({0, 0, 0})
    {}

    Line(Location a, Location b) : A(a), B(b)
    {}

    Location A;
    Location B;

    void GetLineFromPoint(Location &point1, Location &point2, float &k, float &b);

    Location endLine()
    { return B - A; }

    Location GetCenterPoint()
    { return {(A.x + B.x) / 2, (A.y + B.y) / 2, 0}; }

    Axis axis;
};


void Line::GetLineFromPoint(Location &point1, Location &point2, float &k, float &b)
{
    // TODO : check the axis here
    Location diff = point1 - point2;

    if (abs(diff.x) > abs(diff.y)) axis = X;
    else axis = Y;

    if (X == axis)
    {
        k = (point1.y - point2.y) /
            (point1.x - point2.x);
        b = point1.y - k * point1.x;
    } else if (Y == axis)
    {

        k = (point1.x - point2.x) /
            (point1.y - point2.y);
        b = point1.x - k * point1.y;
    }
}

double getRotateAngle(const Location &startLine, const Location &endLine)
{
    double x1 = startLine.x;
    double y1 = startLine.y;
    double x2 = endLine.x;
    double y2 = endLine.y;
    const double epsilon = 1.0e-6;
//    const double nyPI = acos(-1.0);//
    const double nyPI = M_PI;
    double dist, dot, degree, angle;

    // normalize
    dist = sqrt(x1 * x1 + y1 * y1);
    if (dist < epsilon) return 0;
    x1 /= dist;
    y1 /= dist;
    dist = sqrt(x2 * x2 + y2 * y2);
    if (dist < epsilon) return 0;
    x2 /= dist;
    y2 /= dist;
    // dot product
    dot = x1 * x2 + y1 * y2;
    if (fabs(dot - 1.0) <= epsilon)
        angle = 0.0;
    else if (fabs(dot + 1.0) <= epsilon)
        angle = nyPI;
    else
    {
        double cross;
        angle = acos(dot);
        cross = x1 * y2 - x2 * y1;
        if (cross < 0)
        {
            angle = 2 * nyPI - angle;
        }
    }
    degree = angle * 180.0 / nyPI;
    return degree;
}

float test()
{
//    const double nyPI = acos(-1.0);
    const double nyPI = M_PI;

    std::cout << "nyPI: " << nyPI << std::endl;
    std::cout << "cos(nyPI): " << cos(nyPI) << std::endl;

    float x0 = 1;
    float y0 = 0;

    float x1 = -1;
    float y1 = 0;
    float angle = getRotateAngle({x0, y0, 0}, {x1, y1, 0});

    float x2 = x0 * cos(nyPI * angle / 180) - y0 * sin(nyPI * angle / 180);
    float y2 = x0 * sin(nyPI * angle / 180) + y0 * cos(nyPI * angle / 180);
    std::cout << "x1: " << x1 << "y1: " << y1 << "   ------   x2: " << x2 << " , y2: " << y2 << std::endl;

    std::cout << angle << std::endl;
    return 0;
}

struct AAA{
    int aa;

};


int main()
{

    std::list<int>::iterator iter;
    int abc = 10;
    *iter = abc;
    return 0;
    std::cout << sqrt(0) << std::endl;

//    test();
    float k, b;
    Line l;
    Location p1 = {0, 0, 0};
    Location p2 = {1, 1, 0};
    Location p3 = {3, 4, 0};
    Location p4 = {4, 3, 0};

    Location aaa(0, 1, 0);


    Line l1 = {p1, p2};
    Line l2 = {p3, p4};


    float angle = getRotateAngle(l1.endLine(), l2.endLine());
    std::cout << l1.GetCenterPoint().Print() << std::endl;
    std::cout << l2.GetCenterPoint().Print() << std::endl;
    Location move = l2.GetCenterPoint() - l1.GetCenterPoint();
    std::cout << angle << std::endl;
//    const double nyPI = acos(-1.0);
    const double nyPI = M_PI;


    aaa = aaa - l1.GetCenterPoint();
    std::cout << "aaa: " << aaa.Print() << std::endl;

    float xTemp = aaa.x * cos(nyPI * angle / 180) - aaa.y * sin(nyPI * angle / 180);
    float yTemp = aaa.x * sin(nyPI * angle / 180) + aaa.y * cos(nyPI * angle / 180);

    Location endLocation = {xTemp, yTemp, 0};
    Location middleLocation = endLocation;
    endLocation = endLocation + l1.GetCenterPoint();
    std::cout << endLocation.Print() << std::endl;
    endLocation = endLocation + move;
    std::cout << endLocation.Print() << std::endl;
    middleLocation = middleLocation + l2.GetCenterPoint();
    std::cout << middleLocation.Print() << std::endl;


    double r_vec[3] = {1, 1, 0};
    double d_vec[3] = {4, 4, 0};
    double R_matrix[9];
    const cv::Mat M1 = (cv::Mat_<float>(1, 3) << 1, 1, 0);
    cv::Mat M2 = (cv::Mat_<float>(1, 3) << 4, 4, 0);

    //wrong
//    cvRodrigues2(reinterpret_cast<const CvMat *>(&M1), reinterpret_cast<CvMat *>(&M2));


    return 0;
}
