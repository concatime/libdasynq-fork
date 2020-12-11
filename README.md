# Fork of [dasynq](//github.com/davmac314/dasynq)

Synced as of `1ea82938`.

## Build

### Meson

Install [Meson](https://mesonbuild.com) and [Ninja](https://ninja-build.org) (or [samurai](https://git.sr.ht/~mcf/samurai)).

```
meson build
ninja -C build
sudo ninja -C build install
```

### POSIX make

Install one of, but not limited, [bmake](http://www.crufty.net/help/sjg/bmake.html), [GNU Make](https://www.gnu.org/software/make/) or [Schily SunPro Make](http://schilytools.sourceforge.net/sunpromake.html).

```
make -e -f build.make
sudo make -e -f build.make install
```
