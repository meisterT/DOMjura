#include "judgingevent.h"

#include "submissionevent.h"

namespace DJ {
	namespace Model {
		JudgingEvent::JudgingEvent(QString id, QDateTime datetime, QString judgingId, Event *submissionEvent, QObject *parent) : Event(id, datetime, parent) {
			this->judgingId = judgingId;
			this->submissionEvent = submissionEvent;
		}

		void JudgingEvent::setCorrect(bool correct) {
			this->correct = correct;
		}

		QString JudgingEvent::toString() {
			QString s;
			s += "    type         = judging\n";
			s += "    id           = " + this->id + "\n";
			s += "    time         = " + this->datetime.toString("yyyy-MM-dd hh:mm:ss") + "\n";
			s += "    judgingid    = " + this->judgingId + "\n";
			SubmissionEvent *submissionEvent = (SubmissionEvent *)this->submissionEvent;
			s += "    submissionid = " + submissionEvent->getId() + "\n";
			s += "    correct      = " + QString(this->correct ? "yes" : "no") + "\n";
			return s;
		}

		EventType JudgingEvent::getType() {
			return JUDGINGEVENT;
		}
	} // namespace Model
} // namespace DJ