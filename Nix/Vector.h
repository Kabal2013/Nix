#pragma once

#include "CoreDefs.h"
#include "Architecture.h"
#include "Types.h"
#include "VectorHelper.h"


NIX_NAMESPACE_BEGIN


NIX_MEMORY_ALIGNMENT(NIX_MEMORY_ALIGNMENT_SIZE) class Vector
{
public:
    //////////////////////////////////////////////////////////////////////////
    // Constructors
    NIX_INLINE Vector() : m_vec(VectorHelper::GetZero()) {}
    NIX_INLINE Vector(nixFloat _x, nixFloat _y, nixFloat _z) : m_vec(VectorHelper::Set(1.0f, _z, _y, _x)) {}
    NIX_INLINE Vector(nixFloat _x, nixFloat _y, nixFloat _z, nixFloat _w) : m_vec(VectorHelper::Set(_w, _z, _y, _x)) {}
    NIX_INLINE Vector(nixFloat _v) : m_vec(VectorHelper::Splat(_v)) {}
    NIX_INLINE Vector(const Vector& _copy) : m_vec(_copy.m_vec) {}
    NIX_INLINE Vector(Vector&& _copy) noexcept : m_vec(std::move(_copy.m_vec)) {}
    NIX_INLINE Vector(const __nixFloat4& _copy) : m_vec(_copy) {}
    NIX_INLINE Vector(__nixFloat4&& _copy) noexcept : m_vec(std::move(_copy)) {}

    //////////////////////////////////////////////////////////////////////////
    // Operators
    NIX_INLINE Vector& operator= (const Vector& _v)
    {
        this->m_vec = _v.m_vec;
        return *this;
    }
    NIX_INLINE Vector& operator+=(const Vector& _v)
    {
        this->m_vec = VectorHelper::Add(this->m_vec, _v.m_vec);
        return *this;
    }
    NIX_INLINE Vector& operator-=(const Vector& _v)
    {
        this->m_vec = VectorHelper::Sub(this->m_vec, _v.m_vec);
        return *this;
    }
    NIX_INLINE Vector& operator*=(const Vector& _v)
    {
        this->m_vec = VectorHelper::Mul(this->m_vec, _v.m_vec);
        return *this;
    }
    NIX_INLINE Vector& operator/=(const Vector& _v)
    {
        this->m_vec = VectorHelper::Div(this->m_vec, _v.m_vec);
        return *this;
    }
    NIX_INLINE Vector& operator+=(const nixFloat& _s)
    {
        this->m_vec = VectorHelper::Add(this->m_vec, VectorHelper::Splat(_s));
        return *this;
    }
    NIX_INLINE Vector& operator-=(const nixFloat& _s)
    {
        this->m_vec = VectorHelper::Sub(this->m_vec, VectorHelper::Splat(_s));
        return *this;
    }
    NIX_INLINE Vector& operator*=(const nixFloat& _s)
    {
        this->m_vec = VectorHelper::Mul(this->m_vec, VectorHelper::Splat(_s));
        return *this;
    }
    NIX_INLINE Vector& operator/=(const nixFloat& _s)
    {
        this->m_vec = VectorHelper::Div(this->m_vec, VectorHelper::Splat(_s));
        return *this;
    }
    NIX_INLINE Vector& operator++()
    {
        this->m_vec = VectorHelper::Add(this->m_vec, VectorHelper::GetOne());
        return *this;
    }
    NIX_INLINE Vector& operator--()
    {
        this->m_vec = VectorHelper::Sub(this->m_vec, VectorHelper::GetOne());
        return *this;
    }

    //////////////////////////////////////////////////////////////////////////
    // Outer Functions (return new value and do not change local content)
    NIX_INLINE Vector GetAbs()
    {
        return VectorHelper::Abs(m_vec);
    }

    NIX_INLINE Vector GetFloor()
    {
        return VectorHelper::Floor(m_vec);
    }

    NIX_INLINE Vector GetCeil()
    {
        return VectorHelper::Ceil(m_vec);
    }

    // Computes and returns (this * _vecToMul) + _vecToAdd.
    NIX_INLINE Vector GetMulAdd(const Vector& _vecToMul, const Vector& _vecToAdd)
    {
        return VectorHelper::MulAdd(m_vec, _vecToMul.m_vec, _vecToAdd.m_vec);
    }
   
    //////////////////////////////////////////////////////////////////////////
    // Inner Functions (do change local content)
    NIX_INLINE void Abs()
    {
        m_vec = VectorHelper::Abs(m_vec);
    }

    NIX_INLINE void Floor()
    {
        m_vec = VectorHelper::Floor(m_vec);
    }

    NIX_INLINE void Ceil()
    {
        m_vec = VectorHelper::Ceil(m_vec);
    }

    // Computes and set (this * _vecToMul) + _vecToAdd.
    NIX_INLINE Vector MulAdd(const Vector& _vecToMul, const Vector& _vecToAdd)
    {
        m_vec = VectorHelper::MulAdd(m_vec, _vecToMul.m_vec, _vecToAdd.m_vec);
    }

private:
    friend class VectorHelper;

    __nixFloat4 m_vec;
};


NIX_NAMESPACE_END