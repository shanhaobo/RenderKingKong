#include "../../Include/Core/ANNCoreLayer.hpp"

namespace ann
{
    namespace Layer
    {
        void ftest2(::std::initializer_list<int> t)
        {
            sizeof(t);
        }

        void ftest()
        {

            ftest2({ 4, 5, 6 });

            ::std::vector<int> v = { 4, 5, 6 };
        }
    } /// end of namespace Layer
} /// end of namespace ann
