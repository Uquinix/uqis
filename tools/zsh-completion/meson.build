if get_option('zsh-completions')
zsh_completions = [
  '_uqis',
  '_rc-service',
  '_rc-status',
  '_rc-update',
  ]

install_data(zsh_completions,
  install_dir : get_option('datadir') / 'zsh/site-functions')
endif
