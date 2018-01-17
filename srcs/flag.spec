applyflagtwo.c:	if ((block->flag.plus) && block->flag.width && !sign && s[0] != '-')
applyflagtwo.c:		block->flag.width--;
applyflagtwo.c:	if (block->flag.spec != 's' && block->flag.spec != 'c')
applyflagtwo.c:		if (block->flag.width && block->flag.dot)
applyflagtwo.c:			if (block->flag.dot > block->flag.width)
applyflagtwo.c:				block->flag.less = 0;
applyflagtwo.c:	if (block->flag.sharp && (block->flag.spec == 'X' ||
applyflagtwo.c:block->flag.spec == 'x' || block->flag.spec == 'o') && block->flag.dot != -1 &&
applyflagtwo.c:			(!ft_strequ("0", s)) && !block->flag.zero)
applyflagtwo.c:		if (block->flag.spec == 'X')
applyflagtwo.c:		else if (block->flag.spec == 'x')
applyflagtwo.c:		else if (block->flag.spec == 'o')
ft_applybegin.c:	if (block->flag.sharp && block->flag.zero && block->flag.width &&
ft_applybegin.c:			block->flag.spec != 'o')
ft_applybegin.c:		block->flag.width -= 2;
ft_applybegin.c:	if ((block->flag.spec == 'd' || block->flag.spec == 'i'))
ft_applybegin.c:	if (block->flag.dot == -1 && ft_strequ(s, "0"))
ft_applybegin.c:		if (block->flag.spec == 'o' && block->flag.sharp)
ft_applyflag.c:	if (block->flag.zero && block->flag.spec != 's' && block->flag.spec != 'c'
ft_applyflag.c:			&& block->flag.dot == 0)
ft_applyflag.c:		leaked = ft_scs(block->flag.width - (int)ft_strlen(s), '0');
ft_applyflag.c:	if (block->flag.less && !block->flag.zero)
ft_applyflag.c:		leaked = ft_scs((block->flag.width) -
ft_applyflag.c:((int)ft_strlen(s) + block->flag.space), ' ');
ft_applyflag.c:	if (ft_strequ("0", s) && block->flag.dot == -2)
ft_applyflag.c:		block->flag.dot = -1;
ft_applyflag.c:	if (block->flag.neg)
ft_applyflag.c:		block->flag.space = 0;
ft_applyflag.c:	if (block->flag.space && !block->flag.plus)
ft_applyflag.c:	if ((sign || block->flag.neg) && (block->flag.zero || block->flag.dot))
ft_applyflag.c:	else if (block->flag.plus && !sign && s[0] != '-')
ft_applyflag.c:	if (block->flag.dot)
ft_applyflagthree.c:	if (block->flag.sharp && (block->flag.spec == 'X' ||
ft_applyflagthree.c:block->flag.spec == 'x') && block->flag.dot != -1 &&
ft_applyflagthree.c:!ft_strequ("0", s) && block->flag.zero)
ft_applyflagthree.c:		if (block->flag.spec == 'X')
ft_applyflagthree.c:		else if (block->flag.spec == 'x')
ft_applyflagthree.c:		else if (block->flag.spec == 'x')
ft_applyflagthree.c:	if (block->flag.width && !block->flag.zero)
ft_applyflagthree.c:		tmp = ft_scs((block->flag.width) - (((int)ft_strlen(s) +
ft_applyflagthree.c:(block->flag.less ? block->flag.space : 0))), ' ');
ft_applyflagthree.c:		if (block->flag.less)
ft_call.c:	if (((ft_strequ(block->content, "") || block->content == NULL) &&
ft_call.c:				block->flag.spec) && block->next == NULL)
ft_call.c:		ft_strdel(&block->content);
ft_call.c:		block->content = ft_strdup("(null)");
ft_call.c:	else if (block->flag.spec)
ft_call.c:		if (block->flag.spec == '%')
ft_call.c:			block->flag.dot = 0;
ft_call.c:			block->flag.space = 0;
ft_call.c:		block->content = ft_applyflag(block, block->content);
ft_call.c:	block->content = ft_findspec(block, arglst);
ft_call.c:	if (!block->content)
ft_call.c:		return (ft_call(block->next, arglst));
ft_call.c:	if (ft_strequ(block->content, "-nUlLl'-"))
ft_call.c:		return (ft_call(block->next, arglst));
ft_call.c:	if ((block->content)[0] == '-')
ft_call.c:		block->flag.neg = 1;
ft_call.c:	if (block->flag.spec == -1)
ft_call.c:		return (ft_call(block->next, arglst));
ft_call.c:	ft_call(block->next, arglst);
ft_findspec.c:	if (block->flag.spec == 'u' && block->flag.space)
ft_findspec.c:		block->flag.space = 0;
ft_findspec.c:	if (block->flag.spec == 'u' && block->flag.plus)
ft_findspec.c:		block->flag.plus = 0;
ft_findspec.c:	if (block->flag.spec == 'd' || block->flag.spec == 'i')
ft_findspec.c:	else if (block->flag.spec == 'u' || block->flag.spec == 'o' ||
ft_findspec.c:block->flag.spec == 'x' || block->flag.spec == 'X' || block->flag.spec == 'p')
ft_findspec.c:			block->flag.c = va_arg(arglst, wchar_t);
ft_findspec.c:		block->flag.wstr = va_arg(arglst, wchar_t*);
ft_findspec.c:	if (!block->flag.spec)
ft_findspec.c:		return (block->content);
ft_findspec.c:	s = ft_grepspec(block->content);
ft_findspec.c:	ft_strdel(&block->content);
ft_findspec.c:	if (block->flag.spec)
ft_findspec.c:		block->flag.spec = ft_takespec(s);
ft_intc.c:		block->content_size = -1;
ft_mvinlst.c:	if ((block->content)[i] == '%')
ft_mvinlst.c:	if (block->next != NULL)
ft_mvinlst.c:		ft_mvinlst(block->next);
ft_newblck.c:	block->content = ft_strsub(str, head, len);
ft_newblck.c:	block->next = 0;
ft_putflags.c:	if ((block->content)[0] == '%')
ft_putflags.c:		block->flag.spec = 1;
ft_putflags.c:	if ((block->content)[i] == '+')
ft_putflags.c:		block->flag.plus = 1;
ft_putflags.c:	block->flag.dot = ft_atoi(block->content + i);
ft_putflags.c:	if (block->flag.dot == 0 && ('s' == ft_takespec(block->content + 1)))
ft_putflags.c:		block->flag.dot = -1;
ft_putflags.c:	if (block->flag.dot == 0)
ft_putflags.c:		block->flag.dot = -2;
ft_putflags.c:	while (ft_isdigit((block->content)[i]))
ft_putflags.c:	block->flag.width = ft_atoi(block->content + *i);
ft_putflags.c:	while (ft_isdigit((block->content)[*i]))
ft_putflags.c:	while ((block->content)[i])
ft_putflags.c:		if ((block->content)[i] == '.')
ft_putflags.c:		else if ((block->content)[i] == '-')
ft_putflags.c:			block->flag.less = 1;
ft_putflags.c:		else if ((block->content)[i] == '#')
ft_putflags.c:			block->flag.sharp = 1;
ft_putflags.c:		else if ((block->content)[i] == '0')
ft_putflags.c:			block->flag.zero = 1;
ft_putflags.c:		else if ((block->content)[i] == ' ')
ft_putflags.c:			block->flag.space = 1;
ft_putflags.c:		else if (ft_isdigit((block->content)[i]) == 1)
ft_putflags.c:	if (block->flag.zero && block->flag.less)
ft_putflags.c:		block->flag.zero = 0;
ft_putflags.c:	if (block->flag.dot && block->flag.width && block->flag.space)
ft_putflags.c:		block->flag.space = 0;
ft_putspace.c:		block->content = block->content;
ft_putspacetwo.c:	if (block->flag.width)
ifdot.c:	if (block->flag.width > block->flag.dot)
ifdot.c:		if (block->flag.sharp)
ifdot.c:			leak = ft_scs((block->flag.width - (((int)ft_strlen(s)) + 2)), ' ');
ifdot.c:			leak = ft_scs((block->flag.width - ((int)ft_strlen(s) +
ifdot.c:			block->flag.plus)), ' ');
ifdot.c:	if (block->flag.neg && block->flag.dot > (int)ft_strlen(*s) - 1)
ifdot.c:		leaked = ft_scs((block->flag.dot - ((int)ft_strlen(*s) - 1)), '0');
ifdot.c:	else if (block->flag.dot > (int)ft_strlen(*s))
ifdot.c:		leaked = ft_scs((block->flag.dot - ((int)ft_strlen(*s))), '0');
ifdot.c:	if (block->flag.spec == 's' || block->flag.spec == 'c')
ifdot.c:		if (block->flag.dot == -1)
ifdot.c:			if (block->flag.width)
ifdot.c:				s = ft_scs(block->flag.width, ' ');
ifdot.c:		else if (block->flag.dot < (int)ft_strlen(s))
ifdot.c:			s = ft_strndup(s, block->flag.dot);
ifdot.c:	if (block->flag.zero && block->flag.width)
