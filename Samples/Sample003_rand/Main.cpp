#include "../SampleBase.hpp"

#include <iostream>
#include <fstream>


int _tmain(int argc, _TCHAR* argv[])
{
    ::std::ofstream lTxt;

    lTxt.open(_T("D:\\Documents\\MATLAB\\Rand.txt"));

    ::Wiz::R64::Type lRadius, lTheta;
    ::Wiz::R64::Type x, y;

    ::Wiz::Random::Type<::Wiz::R64::Type> tRandom(0, 2500);

    for (::Wiz::I::Type i = 0; i < 1000; ++i)
    {
        lRadius = tRandom.Generate();
    }

    return 0;
}

