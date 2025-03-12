/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:38:34 by tkeil             #+#    #+#             */
/*   Updated: 2025/03/12 19:49:35 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed abs_value(Fixed value) {
	return (value < 0 ? -value : value);
}

bool is_inside(t_point &pt, t_angle &angle) {
	Fixed total = Fixed(0.5f) * abs_value(angle.A.x * (angle.B.y - angle.C.y) + angle.B.x * (angle.C.y - angle.A.y) + angle.C.x * (angle.A.y - angle.B.y));
	Fixed angle1 = Fixed(0.5f) * abs_value(pt.x * (angle.A.y - angle.B.y) + angle.A.x * (angle.B.y - pt.y) + angle.B.x * (pt.y - angle.A.y));
	Fixed angle2 = Fixed(0.5f) * abs_value(pt.x * (angle.B.y - angle.C.y) + angle.B.x * (angle.C.y - pt.y) + angle.C.x * (pt.y - angle.B.y));
	Fixed angle3 = Fixed(0.5f) * abs_value(pt.x * (angle.C.y - angle.A.y) + angle.C.x * (angle.A.y - pt.y) + angle.A.x * (pt.y - angle.C.y));
	return (total == angle1 + angle2 + angle3);
}

int main(void) {
	t_point pt = {Fixed(-1), Fixed(1)};
	t_angle angle = {t_point{Fixed(0), Fixed(0)}, t_point{Fixed(2), Fixed(0)}, t_point{Fixed(0), Fixed(2)}};
	std::cout << (is_inside(pt, angle) ? "it is inside" : "it is not inside") << std::endl;
	return (0);
}
