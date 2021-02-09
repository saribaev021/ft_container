//
// Created by Kanat Saribaew on 1/27/21.
//

#ifndef SFINAE_HPP
#define SFINAE_HPP

template <typename T, typename u>
struct IsSame{
    static constexpr bool value = false;
};
template <typename T>
struct IsSame<T, T>{
    static constexpr bool value = true;
};
template <bool condition, typename Type>
struct EnableIf{};
template<typename Type>
struct EnableIf<true, Type>
{
    typedef Type type;
};

#endif //SFINAE_HPP
