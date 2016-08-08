#ifndef __WHIMSY_ATTRIBUTE_PROVIDER_HPP__ 
#define __WHIMSY_ATTRIBUTE_PROVIDER_HPP__

#include "../Core/WMSFrmwrkFwdDclr.hpp"
#include "./WMSAttrRequest.hpp"

namespace wms
{
    namespace Attr
    {
        namespace Provider
        {
            WMS_CLASS
            {
            protected:

                struct tRequestLayerItem
                {
                    ID32::type          AttrID;
                    ID32::type          RequestID;
                    Attr::Request::ptr  RequestPtr;

                    tRequestLayerItem(ID32::in inAttrID, Attr::Request::ptr inRequestPtr) : AttrID(inAttrID), RequestPtr(inRequestPtr), RequestID(ID32::Invalid)
                    {

                    }
                };
                typedef Array<tRequestLayerItem>::type       tRequestList;

            public:
                type();
                virtual ~type();

                Bool::type Attach(Attr::Module::ptr);
                Void::type Detach();

            protected:
                tRequestList                m_RequestList;
                Attr::Module::ptr           m_AttrModulePtr;
            };
        } /// end of namespace Provider
    } /// end of namespace Attr
} /// end of namespace wms

#endif /// __WHIMSY_ATTRIBUTE_PROVIDER_HPP__
