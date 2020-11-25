we will use structures for each item added,and these structures will be added to another structure which will be an array or list of these items...
each of these items will have its own values...

for example if we have a netfilx seriez the hierarchy will look like:

1.		List
		   |-Object(permanent index)
				|- Name
				|- Date of Release
				|- Date of Completion(if any)
				|- Rating
				|- Genre
				|- Status (Ongoing, Completed, Not yet Aired)
				|- Summary
				|- Overview(if required)
				|- Characters
						|- corresponding Actors
						|- rating
						|- (any more info you want to write)
				|- Actors
					|-corresponding character
					|- (whatever user wants to add)


2.     Genre will have its own database too, so that when user adds a genre to the series, the name of the series will
	   automaticaly get added to genre list.
	   like Genre will look like this:

			Genre
				|-Romance
						|-seriez permanent index from previous list
				|- thriller
				|- Horrer
				|- Comedy
				|-(user can add any genre name they want)


3.     We will also add sorting algorythms and twerk the structure a little to make the process more storage and time efficient.
////////////////////////////////////////////////////////////////////////////////////////////////////
c++ code!
1. we're going to provide 4-5 options
a. sorting movies by the year name so that when the user wants to watch the new movies he / she can sort watch the recent movies
b. sorting according to the Rating
c.for genre!
we're going to use map function where each genre will be given an index or number.
then with the help of vector array and counting sort method we can store the movie in that index.
map<string,int>
indexing every genre
adventure :1
thriller:2
horror:3 etc
making vector which a container similar to array
we will add the movie in that particular index's vector,further movies can be sorted
