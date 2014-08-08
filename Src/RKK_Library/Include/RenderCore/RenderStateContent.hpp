#ifndef __RENDERKINGKONG_RENDERSTATE_CONTENT_HPP__
#define __RENDERKINGKONG_RENDERSTATE_CONTENT_HPP__

#include "../Core/Core.hpp"

namespace rkk
{
    namespace RenderState
    {
        namespace Content
        {
            class type
            {
            public:
                type();
                ~type();
            };
            RKK_DECLARE(type);

            namespace Working
            {
                class type : public Content::type
                {
                public:
                    type();
                    ~type();

                public:
                    Bool::type Update(Content::in inSuper);
                };
                RKK_DECLARE(type);
            } /// end of namespace Working
        } /// end of namespace Content
    } /// namespace RenderState
} /// namespace rkk

#endif /// #ifndef __RENDERKINGKONG_RENDERSTATE_CONTENT_HPP__
