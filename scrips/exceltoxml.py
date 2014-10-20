from xml.etree import ElementTree
from lxml import etree
import sys
from xlrd import open_workbook, xldate_as_tuple

def read_xml(text):
	print open(text).read()


def read_xls(test):
	try:
		excel = open_workbook(test)
		for item in excel.sheets():
			if item.nrows == 0:
				continue
			titleRows = item.row_values(0)
			colNums = len(titleRows)
			titles = []

			root = etree.Element("root")

			for row in titleRows:
				titles.append(row)
			
			for index in xrange(1,item.nrows):
				contentRows = item.row_values(index)
				if len(contentRows) == colNums:
					sub = etree.SubElement(root,"item")
					for rowIndex in xrange(0,len(contentRows)-1):
						subsub = etree.SubElement(sub,titles[rowIndex])
						subsub.text = str(contentRows[0])
				else:
					print "file format error:colume is error"
					sys.exit()


			firstline = item.row_values(1)
			print(etree.tostring(root, pretty_print=True))
			# print len(firstline)
			# for row in firstline:
			# 	print row

	except:
		print "file format error"
		sys.exit()




if __name__ == '__main__':
	# root = etree.Element("root")
	# sub1 = etree.SubElement(root,"child1")
	# sub1.text = "child1content"
	# root.append( etree.Element("child2") )
	# print(etree.tostring(root, pretty_print=True))
	fileName = "/Users/chukie/Desktop/Sheet1.xml"
	excelFileName = "/Users/chukie/Desktop/ragged.xls"
	read_xls(excelFileName)