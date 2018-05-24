1.  How can things go wrong if two processes attempt the above plan at the same time? Is there more than one way things can go wrong?

* the data is not going to be accurate, so wrong things will be done.

2.  what do each of the arguments to `open()` mean?

* first argument, filename
* second argument creates file if not found
* third argument are the permissions allowed on the file

3.  What happens? Do things go as planned and look
    sensible? What do you speculate is happening?

```
  Withdrew $516, new balance $1484
  Only have $0, can't withdraw $130
  Withdrew $323, new balance $1161
  Only have $0, can't withdraw $551
  Withdrew $937, new balance $224
  Only have $0, can't withdraw $744
  Only have $224, can't withdraw $358
  Withdrew $165, new balance $59
  Only have $59, can't withdraw $972
  Only have $59, can't withdraw $779
```

things look weird and out of wack! They don't make sense. Seems like the order is not being respected. 4.

5.  Why is it working? How has adding locks fixed the
    problems you noted in question 1? How is overall performance of the
    application affected?

```
Withdrew $243, new balance $1757
Withdrew $50, new balance $1707
Withdrew $857, new balance $850
Withdrew $664, new balance $186
Only have $186, can't withdraw $471
Only have $186, can't withdraw $278
Withdrew $85, new balance $101
Only have $101, can't withdraw $892
Only have $101, can't withdraw $699
Only have $101, can't withdraw $506
```

this now makes sense, nice!!

the perfomance doesn't seem too bad! Almost the same.
