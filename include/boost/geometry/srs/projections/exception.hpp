// Boost.Geometry

// Copyright (c) 2008-2012 Barend Gehrels, Amsterdam, the Netherlands.

// This file was modified by Oracle on 2017.
// Modifications copyright (c) 2017, Oracle and/or its affiliates.
// Contributed and/or modified by Adam Wulkiewicz, on behalf of Oracle

// Use, modification and distribution is subject to the Boost Software License,
// Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_GEOMETRY_PROJECTIONS_EXCEPTION_HPP
#define BOOST_GEOMETRY_PROJECTIONS_EXCEPTION_HPP


#include <boost/geometry/core/exception.hpp>
#include <boost/geometry/srs/projections/impl/pj_strerrno.hpp>


namespace boost { namespace geometry
{

// TODO: make more for forward/inverse/init/setup
class proj_exception : public geometry::exception
{
public:
    proj_exception(int code = 0)
        : m_code(code)
        , m_msg(projections::detail::pj_strerrno(code))
    {}

    proj_exception(std::string const& msg)
        : m_code(0)
        , m_msg(msg)
    {}

    virtual char const* what() const throw()
    {
        //return "Boost.Geometry Projection exception";
        return m_msg.what();
    }

    int code() const { return m_code; }
private :
    int m_code;
    std::runtime_error m_msg;
};


}} // namespace boost::geometry
#endif // BOOST_GEOMETRY_PROJECTIONS_EXCEPTION_HPP
