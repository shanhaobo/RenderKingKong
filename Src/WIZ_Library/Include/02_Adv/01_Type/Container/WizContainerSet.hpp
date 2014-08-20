#ifndef __WIZ_CONTAINER_SET_HPP__SHANHAOBO_19800429__
#define __WIZ_CONTAINER_SET_HPP__SHANHAOBO_19800429__

#include "../../../01_Basic/01_Type/WizBasicType.hpp"

#include <set>

namespace Wiz
{
    template< class ElementT, class CompT = ::std::less<ElementT> >
    struct Set : private ::std::set<ElementT, CompT>
    {
        typedef typename Set<ElementT, CompT>                   Type;

        //////////////////////////////////////////////////////////////////////////
        typedef typename ElementT                               tElement;
        typedef typename const ElementT                         tElementConst;
        typedef typename ::std::set<tElement, CompT>            tSuper;

        typedef typename tSuper::iterator                       tIterator;
        typedef typename tSuper::const_iterator                 tIteratorConst;
        typedef typename tSuper::reverse_iterator               tReverseIterator;
        typedef typename tSuper::const_reverse_iterator         tConstReverseIterator;
        typedef typename tSuper::iterator::value_type           tValue;
        typedef typename tSuper::const_iterator::value_type     tValueConst;
        typedef typename tSuper::reference                      tReference;
        typedef typename tSuper::const_reference                tReferenceConst;
        //////////////////////////////////////////////////////////////////////////
        typedef typename tSuper::size_type                      tSize;
        //////////////////////////////////////////////////////////////////////////
    public:
        Set() : tSuper(){}
        Set(const tSuper& InSuper) : tSuper(InSuper){}
    public:
        tIterator Begin()
        {
            return tSuper::begin();
        }

        tIteratorConst Begin() const
        {
            return tSuper::begin();
        }

        tIterator End()
        {
            return tSuper::end();
        }

        tIteratorConst End() const
        {
            return tSuper::end();
        }

        ///-----------------------///

        tReverseIterator RBegin()
        {
            return tSuper::rbegin();
        }

        tConstReverseIterator RBegin() const
        {
            return tSuper::rbegin();
        }

        tReverseIterator REnd()
        {
            return tSuper::rend();
        }

        tConstReverseIterator REnd() const
        {
            return tSuper::rend();
        }

        ///-----------------------///

        ::Wiz::Size::Type Size() const
        {
            return ::Wiz::Cast::Static<::Wiz::Size::Type>(tSuper::size());
        }

        ::Wiz::Void::Type Clear()
        {
            tSuper::clear();
        }

        tIterator Erase(tIterator itr)
        {
            return tSuper::erase(itr);
        }

        ///-----------------------///

        tIterator Find(const tElement& v)
        {
            return tSuper::find(v);
        }

        tIteratorConst Find(const tElement& v) const
        {
            return tSuper::find(v);
        }

        ::Wiz::Bool::Type Find(const tElement& v, tIterator& OItr)
        {
            OItr = Find(v);
            return OItr != End();
        }

        ::Wiz::Bool::Type Find(const tElement& v, tIteratorConst& OItr) const
        {
            OItr = Find(v);
            return OItr != End();
        }

        ///-----------------------///

        ::Wiz::Bool::Type HasData(const tElement& v) const
        {
            return tSuper::find(v) != tSuper::end();
        }

        ///-----------------------///

        ::Wiz::Bool::Type Insert(const tElement& i)
        {
            ::std::pair<tIterator, ::Wiz::Bool::Type> Result;

            Result = tSuper::insert(i);

            return Result.second;
        }

        ::Wiz::Bool::Type Insert(const tElement& i, tIterator& Itr)
        {
            ::std::pair<tIterator, ::Wiz::Bool::Type> Result;

            Result = tSuper::insert(i);
            Itr = Result.first;
            return Result.second;
        }


        ::Wiz::Bool::Type InsertUnique(tElement Val)
        {
            if (this->Find(Val) == this->End())
            {
                this->Insert(Val);
                return ::Wiz::Bool::True;
            }
            return ::Wiz::Bool::False;
        }

        ::Wiz::Bool::Type InsertUnique(tElement Val, tIterator& Itr)
        {
            if (this->Find(Val) == this->End())
            {
                Itr = this->Insert(Val);
                return ::Wiz::Bool::True;
            }
            return ::Wiz::Bool::False;
        }

        ::Wiz::Bool::Type Remove(const tElement& ELT)
        {
            tIterator Found = Find(ELT);
            if (Found == End())
            {
                return ::Wiz::Bool::False;
            }

            this->Erase(Found);
            return ::Wiz::Bool::True;
        }

        ::Wiz::Bool::Type Remove(const tElement& ELT, tIterator& Itr)
        {
            tIterator Found = Find(ELT);
            if (Found == End())
            {
                return ::Wiz::Bool::False;
            }

            Itr = this->Erase(Found);
            return ::Wiz::Bool::True;
        }

        ///-----------------------///

        template<class FuncT>
        tIterator FindIf(FuncT Func)
        {
            return ::std::find_if(tSuper::begin(), tSuper::end(), Func);
        }

        template<class FuncT>
        ::Wiz::Void::Type RemoveIf(FuncT Func)
        {
            tSuper::iterator newend = ::std::remove_if(tSuper::begin(), tSuper::end(), Func);
            tSuper::erase(newend, tSuper::end());
        }

        ///-----------------------///
    };
} /// end of namespace Wiz

#endif /*__WIZ_CONTAINER_SET_HPP__SHANHAOBO_19800429__*/
