/**
 * \file GraphicsDevice.hpp
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

#ifndef LITHIUM_GRAPHICS_DEVICE_HPP_INCLUDED
#define LITHIUM_GRAPHICS_DEVICE_HPP_INCLUDED

#include <Lithium/Graphics/BlendState.hpp>
#include <Lithium/Graphics/DepthStencilState.hpp>
#include <Lithium/Graphics/RasterizerState.hpp>
#include <Lithium/Graphics/SamplerState.hpp>
#include <Lithium/Graphics/EffectPass.hpp>
#include <Lithium/Graphics/Viewport.hpp>
#include <Lithium/Graphics/GraphicsDeviceContext.hpp>
#include <Lithium/Graphics/Texture2D.hpp>
#include <Lithium/Graphics/VertexBuffer.hpp>
#include <Lithium/Graphics/IndexBuffer.hpp>

namespace Lithium
{

	class GraphicsDevice
	{
		public:

			/**
			 * Creates an instance of the GraphicsDevice class.
			 */
			GraphicsDevice();

			/**
			 * Destroys an instance of the GraphicsDevice class.
			 */
			~GraphicsDevice();

		public:

			void clear();

			void setClearColor(float r, float g, float b);

			void setEffectPass(EffectPass* effect);

			inline const Viewport& getViewport() const
			{
				return _viewport;
			}

			void setViewport(const Viewport& viewport);

			void bind(GraphicsResource* resource);

			void release(GraphicsResource* resource);

			inline GraphicsDeviceContext* getContext() const
			{
				return _immediateContext;
			}

			void execute(const GraphicsDeviceContext* context);

		//private:

		//----------------------------------------------------------------------
		// Render state methods
		//----------------------------------------------------------------------

		private:

			/**
			 * Binds a BlendState to the renderer.
			 *
			 * \param state The BlendState to bind.
			 */
			void bindBlendState(BlendState* state);

			/**
			 * Releases a BlendState from the renderer.
			 *
			 * \param state The BlendState to release.
			 */
			void releaseBlendState(BlendState* state);

			/**
			 * Binds a DepthStencilState to the renderer.
			 *
			 * \param state The DepthStencilState to bind.
			 */
			void bindDepthStencilState(DepthStencilState* state);

			/**
			 * Releases a DepthStencilState from the renderer.
			 *
			 * \param state The DepthStencilState to release.
			 */
			void releaseDepthStencilState(DepthStencilState* state);

			/**
			 * Binds a RasterizerState to the renderer.
			 *
			 * \param state The RasterizerState to bind.
			 */
			void bindRasterizerState(RasterizerState* state);

			/**
			 * Releases a RasterizerState from the renderer.
			 *
			 * \param state The RasterizerState to release.
			 */
			void releaseRasterizerState(RasterizerState* state);

			/**
			 * Binds a SamplerState to the renderer.
			 *
			 * \param state The SamplerState to bind.
			 */
			void bindSamplerState(SamplerState* state);

			/**
			 * Releases a SamplerState from the renderer.
			 *
			 * \param state The SamplerState to release.
			 */
			void releaseSamplerState(SamplerState* state);

		//----------------------------------------------------------------------
		// EffectPass methods
		//----------------------------------------------------------------------

		private:

			friend class EffectPass;

			/**
			 * Binds an EffectPass to the device.
			 *
			 * \param effectPass The EffectPass to bind.
			 * \param vertexSource The source code for the vertex shader.
			 * \param vertexSourceLength The length of the array containing the vertex shader source code.
			 * \param pixelSource The source code for the pixel shader.
			 * \param pixelSourceLength The length of the array containing the pixel shader source code.
			 */
			void bindEffectPass(
				EffectPass* effectPass,
				const char* vertexSource,
				std::size_t vertexSourceLength,
				const char* pixelSource,
				std::size_t pixelSourceLength
			);

			/**
			 * Releases an EffectPass from the device.
			 *
			 * \param effectPass The EffectPass to release.
			 */
			void releaseEffectPass(EffectPass* effectPass);

		//----------------------------------------------------------------------
		// VertexBuffer methods
		//----------------------------------------------------------------------

		private:

			friend class VertexBuffer;

			void bindVertexBuffer(VertexBuffer* buffer, const void* data, std::size_t vertexSize);
			void releaseVertexBuffer(VertexBuffer* buffer);

		//----------------------------------------------------------------------
		// IndexBuffer methods
		//----------------------------------------------------------------------

		private:

			friend class IndexBuffer;

			void bindIndexBuffer(IndexBuffer* buffer, const void* data, std::size_t indexSize);
			void releaseIndexBuffer(IndexBuffer* buffer);

		//----------------------------------------------------------------------
		// Texture methods
		//----------------------------------------------------------------------

		private:

			void bindTexture2D(Texture2D* texture, const void* data, BufferUsage::Enum bufferUsage);
			void releaseTexture2D(Texture2D* texture);
			void setDataTexture2D(Texture2D* texture, const void* data, std::int32_t x, std::int32_t y, std::int32_t width, std::int32_t height);

			Viewport _viewport;

		//----------------------------------------------------------------------
		// Member variables
		//----------------------------------------------------------------------

		private:

			friend class Texture2D;

			/// The GraphicsDeviceContext associated with the device
			GraphicsDeviceContext* _immediateContext;

	} ; // end class GraphicsDevice

} // end namespace Lithium

#endif // end LITHIUM_GRAPHICS_DEVICE_HPP_INCLUDED
