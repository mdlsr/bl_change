# bl_change
### A stupid-simple tool for setting screen brightness on dell xps 9570 on linux

I've made this for myself. It may need debugging, it might not work properly or inflict some damage.
If this does not stop you, then:
```
make 
sudo make install
```

usage:

`bl_change inc`

or

`bl_change dec`

if you need to increase or decrease brightness. Bind this to some hotkey. 
If you've lxde and openbox you could add 

```
<keybind key="XF86MonBrightnessDown">
    <action name="Execute">
        <command>bl_change dec</command>
    </action>
</keybind>
<keybind key="XF86MonBrightnessUp">
    <action name="Execute">
        <command>bl_change inc</command>
    </action>
</keybind>
```

to `~/.config/openbox/lxde-rc.xml`
