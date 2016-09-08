#!/bin/python

import sys,csv


def getPikaImages (arr):

	#get correct random
	print("		   switch( rand()%" + str(len(arr)) + ") {")
 	
	indexarray=0
	for pika in arr:
		pebblename = "RESOURCE_ID_IMAGE_" + pika.upper()
		print("				case " + str(indexarray) + " :")
		print("				    pika_image=" + pebblename+";")
		print("				    break;")
		indexarray=indexarray+1
	print("}")

finalDict={}

with open( sys.argv[1] ) as csvfile:
	reader = csv.DictReader(csvfile)
	for row in reader:
		
		#Get happiness
		for happiness in filter(len, row['happiness'].split(' ')):
			if ( happiness not in finalDict ):
				finalDict[ '' + happiness ] = {}
			
			for hour in filter(len, row['hours'].split(' ')):
				if ( ''+hour not in finalDict[ '' + happiness ] ):
					finalDict[ '' + happiness ][ '' + hour ] = []
			
				if ( row['name'] not in finalDict[ '' + happiness ][ '' + hour ] ):
					finalDict[ '' + happiness ][ '' + hour ].append( row['name'] )


#now generate C

	
print("switch(pika_happiness) {")

for happiness in finalDict:
	
	print ("  case " + happiness + " :")
	print ("      switch(current_hour) {")
	
	for hour in finalDict[ happiness ]:
		
		print ("	     case " + hour + " :")
		getPikaImages(finalDict[ happiness ][ hour ])		
		print ("	     	break;")	
		
	print ("      }")
	print ("      break;")

print("}")


