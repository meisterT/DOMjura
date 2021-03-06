/** \file rankedteam.h
  * \brief Contains the class for a ranked team and problem.
  */

#ifndef RANKEDTEAM_H
#define RANKEDTEAM_H

#include <QObject>
#include <QHash>

#include "defines.h"
#include "contest.h"

namespace DJ {
namespace Model {
/** A ranked problem.
  */
struct RankedProblem {
	int id; /**< The ID of this problem. */
	QString shortname; /**< The short name of this problem. */
	ProblemState problemState; /**< The state of this problem. */
	int tries; /**< The number of tries for this problem. */
	int timeLastTry; /**< The time of the last try for this problem. */

	/** Makes a copy of a ranked problem.
	  */
	RankedProblem *copy() {
		RankedProblem *c = new RankedProblem();
		c->id = this->id;
		c->shortname = this->shortname;
		c->problemState = this->problemState;
		c->tries = this->tries;
		c->timeLastTry = this->timeLastTry;
		return c;
	}
};

/** A ranked team.
  */
class RankedTeam : public QObject {
	Q_OBJECT
public:
	/** Constructs a new ranked team.
	  * \param id The unique ID for this ranked team.
	  * \param name The name of this team.
	  * \param parent The parent of this object.
	  */
	explicit RankedTeam(int id, QString name, QObject *parent = 0);
	/** Adds / updates a problem.
	  * \param id The ID of the problem to add / update.
	  * \param problem The new problem.
	  */
	void setProblem(int id, RankedProblem *problem, Contest *contest);

	/** Returns the number of solved problems.
	  * \return the number of solved problems.
	  */
	int getNumSolved();
	/** Returns the total time for thist eam.
	  * \return The total time for thist eam.
	  */
	int getTotalTime();
	/** Returns the name of this team.
	  * \return The name of this team.
	  */
	QString getName();
	/** Returns the ID of this team.
	  * \return The ID of this team.
	  */
	int getId();
	/** Returns the number of problems.
	  * \return The number of problems.
	  */
	int getNumProblems();
	/** Returns the i-th problem for this team.
	  * \param i The index to use.
	  * \return The i-th problem for this team.
	  */
	RankedProblem *getProblem(int i);
	/** Returns the problem for the given ID.
	  * \param id The ID to search.
	  * \pre The problem with the specified ID exists.
	  * \return The problem for the given ID.
	  */
	RankedProblem *getProblemById(int id);

private:
	void recalculateData(Contest *contest);

	QString name;
	int id;
	QList<RankedProblem *> problems;
	QHash<int, int> problemsHash;
	int numSolved;
	int totalTime;
};
} // namespace Model
} // namespace DJ

#endif // RANKEDTEAM_H
