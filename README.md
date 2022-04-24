<h1 align="center" style="font-weight: bold">
        strtools
</h1>       

<p align="center">
	<a href="https://github.com/synacktraa/strtools/blob/master/LICENSE">
        <img src="https://img.shields.io/badge/LICENSE-A31F34?style=flat-square&logoWidth=25&logo=data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAANwAAAByCAYAAAA4TL8fAAADvElEQVR4nO3bsYkdVxiG4c2EA6kCY5WgAt2AMuVbgntRC+rgcoeFTRbDcQ3/OxwxjJ8P/vTwBvOE8/J8PteuO47j35cTO47jubNvrfX5RNuvzW1/nWj7ubPt4+PjW21ba33Z2Xb1e9n5OHCn2oC74QHX24ALA27j48CdagPuhgdcbwMuDLiNjwN3qg24Gx5wvQ24MOA2Pg7cqTbgbnjA9TbgwoDb+Dhwp9qAu+EB19uACwNu4+PAnWoD7oYHXG8DLgy4jY8Dd6oNuBsecL0NuDDgNj4O3Kk24G54wPU24MKA2/g4cKfagLvhAdfbgAsDbuPjwJ1qA+6GB1xvAy4MuI2PA3eqDbgbHnC97bLg3t7evr+/v/+z69ZaX2vbWuuPnW1XP+B622XB2YUHXG4DzuYDLrcBZ/MBl9uAs/mAy23A2XzA5TbgbD7gchtwNh9wuQ04mw+43AaczQdcbgPO5gMutwFn8wGX24Cz+YDLbcDZfMDltsuCW2v9vdZ63Xh/nmj7dBzH6657PB4/attvGXC57crgfq69O/M/3OfN39yztv2WAZfbgGttwAGX2oBrbcABl9qAa23AAZfagGttwAGX2oBrbcABl9qAa23AAZfagGttwAGX2oBrbcABl9qAa23AAZfagGttwAGX2oBrbcABl9qAa23AAZfagGttwAGX2oBrbcABl9qAa23AAZfagGttwAGX2oBrbcABl9qAa23AAZfagGttwAGX2oBrbcABl9qAa23AAZfagGttwAGX2oBrbcABl9qAa23AAZfagGttwAGX2oBrbcABl9qAa23AAZfagGttwAGX2oBrbcABl9qAa23AAZfagGttwAGX2oBrbcABl9qAa23AAZfagGttwAGX2oBrbcABl9qAa23AAZfagGttwAGX2oBrbcABl9qAa23AXRXc4/H4cRzH665ba32qbcDlNuCuCu7KAy63AQfcfMDlNuCAmw+43AYccPMBl9uAA24+4HIbcMDNB1xuAw64+YDLbcABNx9wuQ044OYDLrcBB9x8wOU24ICbD7jcBhxw8wGX24ADbj7gchtwwM0HXG4DDrj5gMttwAE3H3C5DTjg5gMutwEH3HzA5TbggJsPuNwGHHDzAZfbgANuPuByG3DAzQdcbgMOuPmAy23AATcfcLkNOODmAy63AQfcfMDlNuCAmw+43AYccPMBl9uAA24+4HIbcMDNB1xuAw64+YDLbcABNx9wuQ044OYDLrcBB9x8wOU24ICbD7jcBhxw8wGX2/7X4P4DxDPxnlw4RDoAAAAASUVORK5CYII=">
    </a>
    <a href="https://github.com/synacktraa/strtools/network/members">
        <img src="https://img.shields.io/github/stars/synacktraa/strtools.svg?style=flat-square&logo=data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAGQAAABkCAYAAABw4pVUAAAABmJLR0QA/wD/AP+gvaeTAAAGHElEQVR4nO2d3asVVRiHn9fPUgstPZIaJCf8OpVIIal9WJZFYR9GEkQdigjKpH9BIerCu6ACLwu6kCxCBEHNi5Ii80Iok2OpcY6mqahodo5fvy7WbBTUs2dmr1kzc/Z6YGDPZuZ9fzPvrFlr1nrXDEQikUgkEolEIpFIpK2xsgW0gqSRwMvAouSv74ENZnahPFVtiqQOSTt1LT9LmlS2vrZD0tfXCUaDr8rW11ZImjdIMBo8ULbOPAwrW0BOVqXY5p3CVURA0kRJ51KUkH5JHWXrzUodS8hbwM0pthsNvFGwlvZG0nBJ+1OUjgZ/SRpetu4hi6QXMwSjwQtl6x6ySNqWIyBby9Y9JJE0W9LlHAGRpHvK1p+WOlXqq8jf1VObJnAt+rIk3QL0AbfmNHEWmGZmp/2pKoa6lJA3yR8MgHFAtyct7Y0kk7Q3Z91xNfskVf4CrLxA4Clgpgc7dwNPerBTKHUIyHsVtVUIla7UJXUCPfi7cATMMrMeT/a8U/US8i5+NRrwtkd73qlsCZE0BugFbvNs+hSuCfyvZ7teqHIJeQ3/wQAYD7xagF0vVLmE7AbuK8j8b8C9ZqaC7OemkiVE0mKKCwZAF/BIgfZzU8mAACuHiI/MVO6WJWkKcBAYWbCri8B0M+sr2E8mggZE0mhgItABTAYmJeuTk/8mATOSJQQ9yXIM+Ac4ChxP1o8m/x03s4FAeloPiKQJwBRgQrLcMcj6ZKp7mxyMfuAkcBj4O/l9o/XeVjInUwdELoNjJbAQd4IbV3flbnslI66UssPADuATMzuWZudUJ1PSPGArxTwXtAMngCVmtrvZhk0DIpe1sRfXWxrJTw8wx8wuDbZRmvv5o8Rg+GAGKZ590gSks3UtkYTpzTZIE5BDHoREHE3PZZo6ZBSwH5jqQ1Eb0wt0NmsSNy0hZnYeN0vpnCdh7cg5YEWa55NUD2lm9iPwGO7pNZKNE8BSM/spzcaZHuokTQc2AbNzCGtH/gCeMbN9aXfI1I1hZgdwEyy3ZxTWjuwAFmQJBuToVzKzk8DTwBdZ920j1gNPmNnxrDvm6uhLKvpuYA2u7yZyhY+BV8ysP8/OPnp7u4F1wKhWbdWci8BKM1vXihEvPbWSHgc24BII2pEzuGbt5lYNees6lzQH1wK7y5fNmnAIeDZNT24avA0WmdkeYAGw05fNGrAbeNBXMMDz6J2ZHcE9QH7r025F2Qw87HtM3vtwapIR+BKutTFUWQcsM7MzZQvJhKT3JV30MLejKlyWtLrIc1b4eLik54EvgTFF+yqYfqDbzNYX6SRIgoKkubgWWF278I8Az5lZ4Q2WYBkjkqbigjI3lE9P7ME1aw+GcBY6UW487q1vdZk3/iuuJXUqlMOgSWvJgdXp3SPDQgYDwpeQ23EJZHVJrhPQkafXNi+h0zoXUZ9ggNO6IKTDMgJSN4JqDh2QhwL780FQzSGbvaOB07g3vdWJAWB83gGnrIQsIfOpXzDAaQ72htOQAanj7apBMO0hA1LHCr1BMO2h+rIMN4mlrvNLTgITzexy0Y5ClZAu6hsMcNPxgiQHhgpIneuPBkGOIVRA6lx/NAhyDLGEpCfIMYQYMZzC0Jn0c2fRLxoIUUJCXFnfJEvRLCzaQd0D8iduNG+5mS0HlgC/F+iv/nWhpF0FZH+ck7Ra0k3X8TdSLtvlTAF+fynjHHpD0jhJFzyflI1yE4ea+Z4mab1n3xflXupcTyQt9XgyeiW9nkPDMmX7xEUzCn3VbNF1iI977gVcFuRsM/s8685mthHXU7AGl1vVKvWtRyRtbfFq3CbJW5eFpE5Jm1rUtMWXnqBIGqH8FWufctyeMmhbJulATm1nJY0oSlthSJqV42AHJH0oaWwAfWMTXwM5dPp49XlYJM3PeJBbyjhQSTMT31m4P7TOlpE0Ru7Tdc3ok7SiAnpXJFqa8Z+kNF+Jqx6SPhrkwM5LWitpXNk6G8g9N61NtN2ID8rWmRu5z9x9pmu/HfWdpK6y9d0ISV2Jxqu5JOlTFfwZvlBDuF3AYmAE8IOZ7Qrht1Xkvqe7CDfleXsyjzISiUQikUgkEolEIpFIJFIO/wOlD3Lf1a3c8QAAAABJRU5ErkJggg==">
    </a>
    <img src="https://app.codacy.com/project/badge/Grade/575bab95b90d4088b13737e7e945992a"/>
    <br>
    <img src="https://img.shields.io/badge/os-linux-red">
    <img src="https://img.shields.io/badge/os-mac-red"></a>
    <img src="https://img.shields.io/badge/os-windows-red"></a>
    </br>
</p>

---
<h4 align="center">
A tool written in C to convert number bases to human readable string and vice versa.
</h4>

---

<h2>
Usage
</h2>

### Compile
> make
---

### Help

>strtools -h

Output:

```nani

Usage: strtools <type|conversion> <input> [ data | file ] -o outfile.txt

|CLI options|:-
   type/conversion:
      -O  converts octal dump to string.
      -B  converts binary dump to string.
      -D  converts decimal dump to string.
      -X  converts hexadecimal dump to string.
    [if -s flag is specified, it converts string to base<int>.]

   input:
      -i  takes next argument as data string.
      -f  takes next argument as filename.

   optional:
      -o  takes next argument as filename.
           (if filename is null, it's set to strtools_out as filename.)
           [if '-o' is not used, result is printed to STDOUT.]


```
---
### __Binary to String__

```bash
./strtools -B -f exfiles/bin.txt
```

Output:

<pre>
I use arch btw thank you.
</pre>

### __String to Binary__

```bash
./strtools.exe -s -B -f exfiles/ones_and_zeroes
```

Output:

<pre>
110001 100111 1110011 100000 1100001 1101110 1100100 100000 110000 100111 1110011
</pre>
---
### __Octal to String__

```bash
./strtools -O -f exfiles/octal.txt
```

Output:

<pre>
<a target="_blank" href="https://www.youtube.com/watch?v=GBIIQ0kP15E">https://www.youtube.com/watch?v=GBIIQ0kP15E</a>
</pre>

### __String to Octal__

```bash
./strtools -s -O -f exfiles/oct_out
```

Output:

<pre>
143 157 156 164 162 151 142 165 164 145 40 72 51
</pre>

---
### __Hexadecimal to String__

```bash
./strtools -X -i "53 74 61 72 20 74 68 69 73 20 70 72 6f 6a 65 63 74 20 3a 29"
```



<pre>
Star this project :)
</pre>

### __String to Hexadecimal__

```bash
./strtools -s -X -f exfiles/AITO
```

Output:

<pre>
41 73 74 72 6F 6E 61 75 74 20 49 6E 20 54 68 65 20 4F 63 65 61 6E 2E
</pre>
---
### __Decimal to String__

```bash
./strtools -D -i "72 97 118 101 32 97 32 110 105 99 101 32 100 97 121 32 40 59"
```

Output:

<pre>
Have a nice day (;
</pre>

### __String to Decimal__

```bash
./strtools -s -D -f exfiles/AITO
```

Output:

<pre>
65 115 116 114 111 110 97 117 116 32 73 110 32 84 104 101 32 79 99 101 97 110 46 
</pre>
---
---

### **Redirecting output to a file:**
---

##### Using the redirection operator↴

```bash
./strtools -X -i "63 6f 6f 6c 20 73 68 69 74" > hex_out.txt
```

##### Using the -o argument with a filename↴

```bash
./strtools -O -i "143 157 156 164 162 151 142 165 164 145 40 72 51" -o oct_out
```

##### Using the -o argument without a filename↴

```bash
./strtools -D -i "105 100 107 32 105 100 99 46" -o
```
>ps: "-o" without a parameter uses the default filename 'strtools_out'

## **License**

### <a target="_blank" href="https://choosealicense.com/licenses/mit/">MIT</a>

Copyright for portions of project [strtools](https://github.com/SynAcktraa/strtools) are held by [Github Account [SynAcktraa](https://github.com/SynAcktraa) Owner, 2022] as part of project [strtools](https://github.com/SynAcktraa/strtools)

All other copyright for project [strtools](https://github.com/SynAcktraa/strtools) are held by [Github Account [SynAcktraa](https://github.com/SynAcktraa) Owner, 2022].

Check the [LICENSE](LICENSE) for more details.