/**
 * \file Vector.hpp
 *
 * \section COPYRIGHT
 *
 * Lithium-Ion Game Engine
 *
 * ---------------------------------------------------------------------
 *
 * Copyright (c) 2011, Don Olmstead
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LITHIUM_VECTOR_HPP_INCLUDED
#define LITHIUM_VECTOR_HPP_INCLUDED

#include <basis/vector2.hpp>
#include <basis/vector3.hpp>
#include <basis/vector4.hpp>

#include <basis/detail/sse_type.hpp>

typedef basis::detail::sse_type<float> simd_type;

typedef basis::vector2<float, simd_type> Vector2f;
typedef basis::vector3<float, simd_type> Vector3f;
typedef basis::vector4<float, simd_type> Vector4f;

#endif // end LITHIUM_VECTOR_HPP_INCLUDED
