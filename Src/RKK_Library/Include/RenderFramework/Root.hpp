#ifndef __RENDERKINGKONG_ROOT_HPP__
#define __RENDERKINGKONG_ROOT_HPP__

#include "./Renderer.hpp"

namespace rkk
{
    namespace Root
    {
        RKK_CLASS
        {
        public:
            type(){}

        public:
            Bool::type ActivePlugin_RDL(Name::in InRDLName);

        public:
            ::rkk::Renderer::ptr m_Renderer;
        };
    } /// namespace Root
} /// namespace rkk

#endif /// #ifndef __RENDERKINGKONG_ROOT_HPP__
