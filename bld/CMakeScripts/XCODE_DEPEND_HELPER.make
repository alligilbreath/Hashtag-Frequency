# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.trending.Debug:
/Users/alligilbreath/Desktop/project8/project_8_example/bld/Debug/trending:
	/bin/rm -f /Users/alligilbreath/Desktop/project8/project_8_example/bld/Debug/trending


PostBuild.trending.Release:
/Users/alligilbreath/Desktop/project8/project_8_example/bld/Release/trending:
	/bin/rm -f /Users/alligilbreath/Desktop/project8/project_8_example/bld/Release/trending


PostBuild.trending.MinSizeRel:
/Users/alligilbreath/Desktop/project8/project_8_example/bld/MinSizeRel/trending:
	/bin/rm -f /Users/alligilbreath/Desktop/project8/project_8_example/bld/MinSizeRel/trending


PostBuild.trending.RelWithDebInfo:
/Users/alligilbreath/Desktop/project8/project_8_example/bld/RelWithDebInfo/trending:
	/bin/rm -f /Users/alligilbreath/Desktop/project8/project_8_example/bld/RelWithDebInfo/trending




# For each target create a dummy ruleso the target does not have to exist
