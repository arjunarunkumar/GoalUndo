/**
 * Unit Tests for GoalUndo class
**/

#include <gtest/gtest.h>
#include "GoalUndo.h"

class GoalUndoTest : public ::testing::Test
{
	protected:
		GoalUndoTest(){}
		virtual ~GoalUndoTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(GoalUndoTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(GoalUndoTest , addGoaloperation)
{
	GoalUndo goal;
	goal.addOperation("square","perimeter");
	goal.addOperation("Area");
	ASSERT_EQ("square",goal.getGoal());
	goal.undoOperation();
	goal.undoOperation("perimeter");
	ASSERT_EQ("",goal.getOperations());
	}

TEST(GoalUndoTest, addGoaloperation1)
{
	GoalUndo goal;
	goal.undoOperation();
	ASSERT_EQ("",goal.getOperations());
}


TEST(GoalUndoTest, addGoaloperation3)
{
	GoalUndo goal;
	goal.addOperation("rectangle","height");
	goal.addOperation("triangle","3sides");
	goal.undoGoal();
	ASSERT_EQ("rectangle",goal.getGoal());
	goal.undoGoal();
	ASSERT_EQ("",goal.getGoal());
}

TEST(GoalUndoTest, CheckemptyORpop)
{
  GoalUndo goal;
  goal.undoGoal();
  ASSERT_EQ("",goal.getGoal());
}


TEST(GoalUndoTest, CheckemptyORpop1)
{
	GoalUndo goal;
	goal.addOperation("diameter");
	ASSERT_EQ("diameter",goal.getOperations());
	goal.undoOperation();
	goal.undoOperation();
	ASSERT_EQ("",goal.getOperations());
}

TEST(GoalUndoTest, CheckemptyORpop2)
{
	GoalUndo goal;
	goal.addOperation("circle","radius");
	goal.addOperation("surfacearea");
	ASSERT_EQ("radius surfacearea",goal.getOperations());
}
