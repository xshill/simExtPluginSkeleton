#include "functions.h"

#include "scriptFunctionData.h"
#include "simExtOpenCV.h"
#include "stackArray.h"
#include "stackMap.h"
#include "simLib.h"

#include <iostream>

#include <opencv2/opencv.hpp>



#define LUA_LOL_COMMAND "simOpenCV.test" // the name of the new Lua command

const int inArgs_CREATE[]={
    1,
    sim_script_arg_int32, 0,
};

void LUA_LOL_CALLBACK(SScriptCallBack* cb)
{
    CScriptFunctionData D;

    if (D.readDataFromStack(cb->stackID, inArgs_CREATE, inArgs_CREATE[0], LUA_LOL_COMMAND))
    {
        std::vector<CScriptFunctionDataItem>* inData = D.getInDataPtr();
        int res[10] = {0};
        int sensorHandle = inData->at(0).int32Data[0];
        float* image = simGetVisionSensorImage(sensorHandle);
        simGetVisionSensorResolution(sensorHandle, res);

        cv::Mat cvImage(cv::Size(res[0], res[1]), CV_8U, 3);

        std::cout << "Resolution: " << res[0] << "x" << res[1] << std::endl;

        //from v-rep to OpenCV...
        //remeber that colors in opencv Mat are ordered as BGR
        for (unsigned int i=0;i<res[1];i++){
            for (unsigned int j=0;j<res[0];j++){
                int r,g,b;
                r=round(255*image[3*((res[1]-i)*res[0]+j)+0]);
                g=round(255*image[3*((res[1]-i)*res[0]+j)+1]);
                b=round(255*image[3*((res[1]-i)*res[0]+j)+2]);

                // cvImage.at<cv::Vec3b>(i,j)[0] = (uchar)b;
                // cvImage.at<cv::Vec3b>(i,j)[1] = (uchar)g;
                // cvImage.at<cv::Vec3b>(i,j)[2] = (uchar)r;
            }
        }

        std::cout << cvImage.channels() << std::endl;
        // cv::imwrite("lol.png", cvImage);
        simReleaseBuffer((char*)image);
    }

    // D.pushOutData(CScriptFunctionDataItem(handle));
    // D.writeDataToStack(cb->stackID);
}



void registerLuaFunctions()
{
    std::cout << "Registering my shit mang" << std::endl;
    simRegisterScriptCallbackFunction(
        "simOpenCV.test@OpenCV",
        "...=simOpenCV.test()",
        LUA_LOL_CALLBACK
    );
}