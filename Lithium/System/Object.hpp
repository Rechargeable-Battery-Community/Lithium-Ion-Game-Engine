/**
 * \file Object.hpp
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

#ifndef LITHIUM_OBJECT_HPP_INCLUDED
#define LITHIUM_OBJECT_HPP_INCLUDED

#include <Lithium/LithiumCoreLIB.hpp>
#include <Lithium/System/Includes.hpp>

namespace Lithium
{
	/**
	 * Common base class for objects.
	 *
	 * \author Don Olmstead
	 * \version 0.1
	 */
	class LITHIUM_CORE_ITEM Object
	{
		//----------------------------------------------------------------------
		// Construction/Destruction
		//----------------------------------------------------------------------

		protected:

			/**
			 * Creates an instance of the Object class.
			 */
			Object();

			/**
			 * Destroys an instance of the Object class.
			 */
			~Object();

		//----------------------------------------------------------------------
		// Class information
		//----------------------------------------------------------------------

		public:

			/**
			 * Gets the type information for the instance.
			 *
			 * \returns The type information for the instance.
			 */
			virtual const rtl::class_info& getType() const
			{
				return __classInfo;
			}

			/**
			 * Checks to see if the Object is the same from the given type.
			 *
			 * \param type The type information to compare to.
			 * \returns \b true \b if the object is the same type; \b false \b otherwise.
			 */
			inline bool isExactly(const rtl::class_info& type) const
			{
				return getType().is_exactly(type);
			}

			/**
			 * Checks to see if the Object was derived from the given type.
			 *
			 * \param type The type information to compare to.
			 * \returns \b true \b if the instance is derived from the type; \b false \b otherwise.
			 */
			inline bool isDerived(const rtl::class_info& rtti) const
			{
				return getType().is_derived(rtti);
			}

			/**
			 * Gets the type information for the class.
			 *
			 * \returns The type information for the class.
			 */
			inline static const rtl::class_info& typeOf()
			{
				return __classInfo;
			}

		private:

			/// The type information
			static rtl::class_info __classInfo;

	} ; // end class Object

} // end namespace Lithium

//----------------------------------------------------------------------
// Type information
//----------------------------------------------------------------------

/**
 * Declares the type information for the class.
 */
#define LITHIUM_DECLARE_TYPE_INFO \
	public: \
		virtual const rtl::class_info& getType() const \
		{ \
			return __classInfo; \
		} \
	\
		inline static const rtl::class_info& typeOf() \
		{ \
			return __classInfo; \
		} \
	\
	private: \
		static rtl::class_info __classInfo;

/**
 * Implements the type information for the class.
 *
 * \param namespaceName The namespace of the class.
 * \param className The name of the class.
 * \param baseClass The base class that the class is derived from
 */
#define LITHIUM_IMPLEMENT_TYPE_INFO(namespaceName, className, baseClass) \
rtl::class_info className::__classInfo(#namespaceName"."#className, &baseClass::typeOf());

#endif // end LITHIUM_OBJECT_HPP_INCLUDED
