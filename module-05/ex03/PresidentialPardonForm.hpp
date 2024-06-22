/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:03:26 by mel-aini          #+#    #+#             */
/*   Updated: 2023/11/27 11:24:09 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& P);
		PresidentialPardonForm& operator= (const PresidentialPardonForm& P);
		~PresidentialPardonForm();

		PresidentialPardonForm(const std::string& target);

		const std::string& getTarget() const;
		void	executeFormAction() const;
};