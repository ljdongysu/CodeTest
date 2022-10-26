#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <unistd.h>
#include <fstream>

void GetBoxY2Depth(std::string file, std::vector<int> &boxYs, std::vector<float> &depths)
{
    std::ifstream fin(file);
    std::string temp;
    fin >> temp>>temp;

    while (not fin.eof())
    {
        fin >> temp;
        int boxY;
        float depth;
        float unused;
        sscanf(temp.c_str(), "%d,%f,%f,,",&boxY, &depth, &unused);
        boxYs.push_back(boxY);
        depths.push_back(depth);
    }
}

void GetValue(std::string fileBox, std::string fileDepth, std::vector<int> &boxYs, std::vector<float> &depths)
{
    if (not (access(fileBox.c_str(), 0) == 0))
    {
        std::cout<<"file: "<<fileBox<<" not exist, return"<<std::endl;
        return;
    }
    if (not (access(fileDepth.c_str(), 0) == 0))
    {
        std::cout<<"file: "<<fileDepth<<" not exist, return"<<std::endl;
        return;
    }
    std::ifstream finBox(fileBox);
    std::ifstream finDepth(fileDepth);
    while (not finBox.eof())
    {
        std::string boxStr;
        int boxY;

        finBox >> boxStr;
        sscanf(boxStr.c_str(),"%d", &boxY);
        boxYs.push_back(boxY);
    }

    while (not finDepth.eof())
    {
        std::string depthStr;
        float depth;

        finDepth >> depthStr;
        sscanf(depthStr.c_str(),"%f,", &depth);
        depths.push_back(depth);
    }
}

void FindTrueBoxY(const std::vector<int> &boxYs, const std::vector<float> &depths, const float trueDepth, float &trueBoxY)
{
    for (int i = 0; i < boxYs.size(); ++i)
    {
        if (trueDepth > depths[i])
        {
            trueBoxY = boxYs[i];
            return;
        }
    }

}

struct PointTest
{
    float x;
    float y;
    PointTest(float x1,float y1)
    {
        x = x1;
        y = y1;
    }
};
#include<cmath>
#include <vector>
#include <memory.h>
#include "map"

namespace sensor_srvs {
    enum Resolution : uint8_t { RES_640X400, RES_1280X800, LAST };
    struct CameraParameter{
        std::string name;
    };
}

int main(int argc, char *argv[])
{
//    sensor_srvs::Resolution sensorResolution = sensor_srvs::Resolution::RES_640X400;
//    std::map<sensor_srvs::Resolution, sensor_srvs::CameraParameter> camera;
//    sensor_srvs::CameraParameter name ;
//    name.name = "name1111";
//    camera[sensor_srvs::Resolution::RES_640X400] = name;
//
//    if (camera.find(sensorResolution) != camera.end())
//    {
//        std::cout << "exist!\n" << std::endl;
//        std::cout << camera.at(sensorResolution).name << std::endl;
//    }
//    else
//    {
//        std::cout<<"not exist!\n"<<std::endl;
//
//    }

    double TSC[16];
    for (int i = 0; i < 16; ++i)
    {
        TSC[i] = i;
    }
    double TSC_1[16];
    memcpy(TSC_1,TSC,16*sizeof(TSC_1[0] ));

    for (int i = 0; i < 16; ++i)
    {
        std::cout<<TSC_1[i] <<" ";
    }
    return 0;

    std::vector<PointTest> pointsA;
    std::vector<PointTest> pointsB;
    pointsA.push_back(PointTest(0.54,8.81));
    pointsA.push_back(PointTest(0.53,8.71));
    pointsA.push_back(PointTest(0.54,8.67));
    pointsA.push_back(PointTest(0.53,8.72));
    pointsA.push_back(PointTest(0.53,8.74));
    pointsA.push_back(PointTest(0.54,8.82));
    pointsA.push_back(PointTest(0.53,8.84));


    pointsB.push_back(PointTest(0.52,8.39));
    pointsB.push_back(PointTest(0.53,8.38));
    pointsB.push_back(PointTest(0.53,8.41));
    pointsB.push_back(PointTest(0.51,8.39));
    pointsB.push_back(PointTest(0.51,8.43));
    pointsB.push_back(PointTest(0.51,8.43));
    pointsB.push_back(PointTest(0.54,8.46));
//    pointsB.push_back(PointTest(0.53,8.84));
    float minDistance = 10;
    int tempA,tempB;
    for (int i = 0; i < pointsA.size(); ++i)
    {
        PointTest a = pointsA.at(i);
        for (int j = 0; j < pointsB.size(); ++j)
        {
            PointTest b = pointsB.at(j);

            float distance =sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
            if (minDistance > distance)
            {
                tempA = i;
                tempB = j;
                minDistance = distance;
            }
        }
    }
    std::cout<<minDistance<<std::endl;
    std::cout<<"i:" << tempA<<"j:"<<tempB<<std::endl;
    return 0;
    std::string box2DepthFile = argv[1];
    std::string fileBox = argv[2];
    std::string fileDepth = argv[3];
    std::vector<int> boxYs;
    std::vector<float> depths;
    std::vector<int> caseBoxYs;
    std::vector<float> caseDepths;
    std::string boxExtendFile = fileDepth.substr(0, fileDepth.find_last_of('/') + 1) + "boxextendfile.csv";
    std::cout<<"before ofstream"<<std::endl;
    std::ofstream fout(boxExtendFile);
    std::cout<<"after ofstream"<<std::endl;

    GetBoxY2Depth(box2DepthFile,boxYs,depths);
    std::cout<<"after GetBox"<<std::endl;

    if(boxYs.size() != depths.size())
    {
        std::cout<<"===================file : "<<box2DepthFile<<"boxYs': length not equal to depths' length"
                 <<", stop!=============================="<<std::endl;

        return 0;
    }

    GetValue(fileBox, fileDepth, caseBoxYs, caseDepths);
    std::cout<<"after GetValue"<<std::endl;
    fout<<"original_Y"<<","<<"extend_Y"<<std::endl;

    if(caseBoxYs.size() != caseDepths.size())
    {
        std::cout<<"===================file : "<<fileBox<<","<<fileDepth<<"boxYs': length not equal to depths' length"
                 <<", stop!=============================="<<std::endl;

        return 0;
    }

    for (int i = 0; i < caseBoxYs.size(); ++i)
    {
        float trueBoxY;
        FindTrueBoxY(boxYs, depths, caseDepths[i],trueBoxY);
        fout << caseBoxYs[i] <<", "<<trueBoxY<<std::endl;
    }
    fout.close();

}
