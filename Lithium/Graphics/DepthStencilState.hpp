/**
 * \file DepthStencilState.hpp
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

#ifndef LITHIUM_DEPTH_STENCIL_STATE_HPP_INCLUDED
#define LITHIUM_DEPTH_STENCIL_STATE_HPP_INCLUDED

#include <Lithium/LithiumGraphicsLIB.hpp>
#include <Lithium/Graphics/GraphicsResource.hpp>
#include <Lithium/Graphics/CompareFunction.hpp>
#include <Lithium/Graphics/StencilOperation.hpp>

namespace Lithium
{
	/**
	 * Contains state for the depth and stencil buffers.
	 *
	 * \author Don Olmstead
	 * \version 0.1
	 */
	class DepthStencilState : public GraphicsResource
	{
		LITHIUM_DECLARE_TYPE_INFO;

		//----------------------------------------------------------------------
		// Construction/Destruction
		//----------------------------------------------------------------------

		public:

			/**
			 * Creates an instance of the DepthStencilState class.
			 */
			DepthStencilState();

			/**
			 * Destroys an instance of the DepthStencilState class.
			 */
			virtual ~DepthStencilState();

		//----------------------------------------------------------------------
		// Properties
		//----------------------------------------------------------------------

		public:

			/**
			 * Gets whether depth buffering is enabled.
			 *
			 * \returns \b true \b if depth buffering is enabled; \b false \b otherwise.
			 */
			inline bool isDepthEnabled() const
			{
				return _depthEnabled;
			}

			/**
			 * Sets whether depth buffering is enabled.
			 *
			 * \param value Whether depth buffering is enabled.
			 */
			void setDepthEnabled(bool value);

			/**
			 * Gets whether writing to the depth buffer is enabled.
			 *
			 * \returns \b true \b if writing to the depth buffer is enabled; \b false \b otherwise.
			 */
			inline bool isDepthWriteEnabled() const
			{
				return _depthWriteEnabled;
			}

			/**
			 * Sets whether writing to the depth buffer is enabled.
			 *
			 * \param value Whether writing to the depth buffer is enabled.
			 */
			void setDepthWriteEnabled(bool value);

			/**
			 * Gets the comparison function for the depth buffer test.
			 *
			 * \returns The comparison function for the depth buffer test.
			 */
			inline CompareFunction::Enum getDepthFunction() const
			{
				return _depthFunction;
			}

			/**
			 * Sets the comparison function for the depth buffer test.
			 *
			 * \param function The comparison function for the depth buffer test.
			 */
			void setDepthFunction(CompareFunction::Enum function);

			/**
			 * Gets whether the stencil buffer is enabled.
			 *
			 * \returns \b true \b if the stencil buffer is enabled; \b false \b otherwise.
			 */
			inline bool isStencilEnabled() const
			{
				return _stencilEnabled;
			}

			/**
			 * Sets whether the stencil buffer is enabled.
			 *
			 * \param value Whether the stencil buffer is enabled.
			 */
			void setStencilEnabled(bool value);

			/**
			 * Gets the stencil buffer read mask.
			 *
			 * \returns The stencil buffer read mask.
			 */
			inline std::int32_t getStencilReadMask() const
			{
				return _stencilBufferReadMask;
			}

			/**
			 * Sets the stencil buffer read mask.
			 *
			 * \param mask The stencil buffer read mask.
			 */
			void setStencilReadMask(std::int32_t mask);

			/**
			 * Gets the stencil buffer write mask.
			 *
			 * \returns The stencil buffer write mask.
			 */
			inline std::int32_t getStencilWriteMask() const
			{
				return _stencilWriteMask;
			}

			/**
			 * Sets the stencil buffer write mask.
			 *
			 * \param mask The stencil buffer write mask.
			 */
			void setStencilWriteMask(std::int32_t mask);

			/**
			 * Gets the reference for the stencil test.
			 *
			 * \returns The reference for the stencil test.
			 */
			inline std::int32_t getStencilReference() const
			{
				return _stencilReference;
			}

			/**
			 * Sets the reference for the stencil test.
			 *
			 * \param reference The reference for the stencil test.
			 */
			void setStencilReference(std::int32_t reference);

			/**
			 * Gets the comparison function to use for stencil tests.
			 *
			 * This test is performed on front facing polygons.
			 *
			 * \returns The comparison function to use for stencil tests.
			 */
			inline CompareFunction::Enum getFrontStencilFunction() const
			{
				return _frontStencilFunction;
			}

			/**
			 * Sets the comparison function to use for stencil tests.
			 *
			 * This test is performed on front facing polygons.
			 *
			 * \param function The comparison function to use for stencil tests.
			 */
			void setFrontStencilFunction(CompareFunction::Enum function);

			/**
			 * Gets the stencil operation to perform if both the stencil and depth tests pass.
			 *
			 * This test is performed on front facing polygons.
			 *
			 * \returns The stencil operation to perform if both the stencil and depth tests pass.
			 */
			inline StencilOperation::Enum getFrontStencilPass() const
			{
				return _frontStencilPassOperation;
			}

			/**
			 * Sets the stencil operation to perform if both the stencil and depth tests pass.
			 *
			 * This test is performed on front facing polygons.
			 *
			 * \param operation The stencil operation to perform if both the stencil and depth tests pass.
			 */
			void setFrontStencilPass(StencilOperation::Enum operation);

			/**
			 * Gets the stencil operation to perform if the stencil test fails.
			 *
			 * This test is performed on front facing polygons.
			 *
			 * \param operation The stencil operation to perform if the stencil test fails.
			 */
			inline StencilOperation::Enum getFrontStencilFail() const
			{
				return _frontStencilFailOperation;
			}

			/**
			 * Gets the stencil operation to perform if the stencil test fails.
			 *
			 * This test is performed on front facing polygons.
			 *
			 * \param operation The stencil operation to perform if the stencil test fails.
			 */
			void setFrontStencilFail(StencilOperation::Enum operation);

			/**
			 * Gets the stencil operation to perform if the stencil test passes and the depth buffer test fails.
			 *
			 * This test is performed on front facing polygons.
			 *
			 * \returns The stencil operation to perform if the stencil test passes and the depth buffer test fails.
			 */
			inline StencilOperation::Enum getFrontStencilPassDepthFailOperation() const
			{
				return _frontStencilPassDepthFailOperation;
			}

			/**
			 * Sets the stencil operation to perform if the stencil test passes and the depth buffer test fails.
			 *
			 * This test is performed on front facing polygons.
			 *
			 * \param operation The stencil operation to perform if the stencil test passes and the depth buffer test fails.
			 */
			void setFrontStencilPassDepthFailOperation(StencilOperation::Enum operation);

			/**
			 * Gets the comparison function to use for stencil tests.
			 *
			 * This test is performed on back facing polygons.
			 *
			 * \returns The comparison function to use for stencil tests.
			 */
			inline CompareFunction::Enum getBackStencilFunction() const
			{
				return _backStencilFunction;
			}

			/**
			 * Sets the comparison function to use for stencil tests.
			 *
			 * This test is performed on back facing polygons.
			 *
			 * \param function The comparison function to use for stencil tests.
			 */
			void setBackStencilFunction(CompareFunction::Enum function);

			/**
			 * Gets the stencil operation to perform if both the stencil and depth tests pass.
			 *
			 * This test is performed on back facing polygons.
			 *
			 * \returns The stencil operation to perform if both the stencil and depth tests pass.
			 */
			inline StencilOperation::Enum getBackStencilPass() const
			{
				return _backStencilPassOperation;
			}

			/**
			 * Sets the stencil operation to perform if both the stencil and depth tests pass.
			 *
			 * This test is performed on back facing polygons.
			 *
			 * \param operation The stencil operation to perform if both the stencil and depth tests pass.
			 */
			void setBackStencilPass(StencilOperation::Enum operation);

			/**
			 * Gets the stencil operation to perform if the stencil test fails.
			 *
			 * This test is performed on back facing polygons.
			 *
			 * \param operation The stencil operation to perform if the stencil test fails.
			 */
			inline StencilOperation::Enum getBackStencilFail() const
			{
				return _backStencilFailOperation;
			}

			/**
			 * Gets the stencil operation to perform if the stencil test fails.
			 *
			 * This test is performed on back facing polygons.
			 *
			 * \param operation The stencil operation to perform if the stencil test fails.
			 */
			void setBackStencilFail(StencilOperation::Enum operation);

			/**
			 * Gets the stencil operation to perform if the stencil test passes and the depth buffer test fails.
			 *
			 * This test is performed on back facing polygons.
			 *
			 * \returns The stencil operation to perform if the stencil test passes and the depth buffer test fails.
			 */
			inline StencilOperation::Enum getBackStencilPassDepthFailOperation() const
			{
				return _backStencilPassDepthFailOperation;
			}

			/**
			 * Sets the stencil operation to perform if the stencil test passes and the depth buffer test fails.
			 *
			 * This test is performed on back facing polygons.
			 *
			 * \param operation The stencil operation to perform if the stencil test passes and the depth buffer test fails.
			 */
			void setBackStencilPassDepthFailOperation(StencilOperation::Enum operation);

		//----------------------------------------------------------------------
		// Member variables
		//----------------------------------------------------------------------

		private:

			/// Whether the depth buffer is enabled
			bool _depthEnabled;
			/// Whether writing to the depth buffer is enabled
			bool _depthWriteEnabled;
			/// Whether the stencil buffer is enabled
			bool _stencilEnabled;
			
			/// Comparison function for the depth buffer test
			CompareFunction::Enum _depthFunction;
			
			/// Stencil buffer read mask
			std::int32_t _stencilBufferReadMask;
			/// Stencil buffer write mask	
			std::int32_t _stencilWriteMask;
			/// Reference value for the stencil test
			std::int32_t _stencilReference;

			/// Comparison function to use for stencil tests on front facing polygons
			CompareFunction::Enum _frontStencilFunction;
			/// Stencil operation to perform if both the stencil and depth tests pass on front facing polygons
			StencilOperation::Enum _frontStencilPassOperation;
			/// Stencil operation to perform if the stencil test fails on front facing polygons
			StencilOperation::Enum _frontStencilFailOperation;
			/// Stencil operation to perform if the stencil test passes and the depth buffer test fails on front facing polygons
			StencilOperation::Enum _frontStencilPassDepthFailOperation;

			/// Comparison function to use for stencil tests on back facing polygons
			CompareFunction::Enum _backStencilFunction;
			/// Stencil operation to perform if both the stencil and depth tests pass on back facing polygons
			StencilOperation::Enum _backStencilPassOperation;
			/// Stencil operation to perform if the stencil test fails on back facing polygons
			StencilOperation::Enum _backStencilFailOperation;
			/// Stencil operation to perform if the stencil test passes and the depth buffer test fails on back facing polygons
			StencilOperation::Enum _backStencilPassDepthFailOperation;

	} ; // end class DepthStencilState

} // end namespace Lithium

#endif // end LITHIUM_DEPTH_STENCIL_STATE_HPP_INCLUDED
