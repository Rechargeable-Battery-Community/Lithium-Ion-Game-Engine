/**
 * \file OpenGLMappings.cpp
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

#include "OpenGLMappings.hpp"
using namespace Lithium;

//---------------------------------------------------------------------

GLenum OpenGLMappings::blend[Blend::Size] =
{
	GL_ZERO,                     // Zero
	GL_ONE,                      // One
	GL_SRC_COLOR,                // SourceColor
	GL_ONE_MINUS_SRC_COLOR,      // InverseSourceColor
	GL_SRC_ALPHA,                // SourceAlpha
	GL_ONE_MINUS_SRC_ALPHA,      // InverseSourceAlpha
	GL_DST_ALPHA,                // DestinationAlpha
	GL_ONE_MINUS_DST_ALPHA,      // InverseDestinationAlpha
	GL_CONSTANT_COLOR,           // DestinationColor
	GL_ONE_MINUS_CONSTANT_COLOR, // InverseDestinationColor
	GL_SRC_ALPHA_SATURATE,       // SourceAlphaSaturation
	GL_CONSTANT_COLOR,           // BlendFactor
	GL_ONE_MINUS_CONSTANT_COLOR  // InverseBlendFactor
} ;

//---------------------------------------------------------------------

GLenum OpenGLMappings::blendFunction[BlendFunction::Size] =
{
	GL_FUNC_ADD,              // Add
	GL_MAX,                   // Max
	GL_MIN,                   // Min
	GL_FUNC_REVERSE_SUBTRACT, // ReverseSubtract
	GL_FUNC_SUBTRACT          // Subtract
} ;

//---------------------------------------------------------------------

GLenum OpenGLMappings::textureAddressMode[TextureAddressMode::Size] =
{
	GL_CLAMP_TO_EDGE,   // Clamp
	GL_MIRRORED_REPEAT, // Mirror
	GL_REPEAT           // Wrap
} ;

//---------------------------------------------------------------------

GLenum OpenGLMappings::textureFilterMin[TextureFilter::Size] =
{
	GL_LINEAR,                 // Linear
	GL_NEAREST,                // Point
	0,                         // Anisotropic (Enabled through an extension)
	GL_LINEAR_MIPMAP_NEAREST,  // LinearMipPoint
	GL_NEAREST_MIPMAP_LINEAR,  // PointMipLinear
	GL_LINEAR_MIPMAP_LINEAR,   // MinLinearMagPointMipLinear
	GL_LINEAR_MIPMAP_NEAREST,  // MinLinearMagPointMipPoint
	GL_NEAREST_MIPMAP_LINEAR,  // MinPointMagLinearMipLinear
	GL_NEAREST_MIPMAP_NEAREST  // MinPointMagLinearMipPoint
} ;

//---------------------------------------------------------------------

GLenum OpenGLMappings::textureFilterMag[TextureFilter::Size] =
{
	GL_LINEAR,                 // Linear
	GL_NEAREST,                // Point
	0,                         // Anisotropic (Enabled through an extension)
	GL_LINEAR_MIPMAP_NEAREST,  // LinearMipPoint
	GL_NEAREST_MIPMAP_LINEAR,  // PointMipLinear
	GL_NEAREST_MIPMAP_LINEAR,  // MinLinearMagPointMipLinear
	GL_NEAREST_MIPMAP_NEAREST, // MinLinearMagPointMipPoint
	GL_LINEAR_MIPMAP_LINEAR,   // MinPointMagLinearMipLinear
	GL_LINEAR_MIPMAP_NEAREST   // MinPointMagLinearMipPoint
} ;

//---------------------------------------------------------------------

GLenum OpenGLMappings::bufferUsage[BufferUsage::Size] =
{
	GL_STATIC_DRAW,  // Static
	GL_DYNAMIC_DRAW, // Dynamic
	GL_STREAM_DRAW   // Stream
} ;

//---------------------------------------------------------------------

GLenum OpenGLMappings::indexElementSize[IndexElementSize::Size] =
{
	GL_UNSIGNED_SHORT, // SixteenBits
	GL_UNSIGNED_INT    // ThirtyTwoBits
} ;

//---------------------------------------------------------------------

GLuint OpenGLMappings::vertexElement[VertexElementUsage::Size] =
{
	0, // Position
	2, // TextureCoordinate
	4  // Normal
} ;

//---------------------------------------------------------------------

const char* OpenGLMappings::vertexElementNames[VertexElementUsage::Size] =
{
	"position%d", // Position
	"texCoord%d", // TextureCoordinate
	"normal%d",   // Normal
} ;

//---------------------------------------------------------------------

GLenum OpenGLMappings::vertexElementFormat[VertexElementFormat::Size] =
{
	GL_FLOAT, // Scalar
	GL_FLOAT, // Vector2
	GL_FLOAT, // Vector3
	GL_FLOAT, // Vector4
} ;

//---------------------------------------------------------------------

GLint OpenGLMappings::vertexElementSize[VertexElementFormat::Size] =
{
	1, // Scalar
	2, // Vector2
	3, // Vector3
	4, // Vector4
} ;
